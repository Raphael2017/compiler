#include <assert.h>
#include <syntax_tree.h>
#include "translate.h"
#include "frame.h"
#include "symbol.h"
#include "type_info.h"
#include "entry.h"
#include "syntax_tree.h"
#include <string.h>
#include <list>

#define INT_TP          "<INT>"
#define STRING_TP       "<STRING>"

struct TranslateExp {
    TypeInfo *type_;
    void* exp_;
};

struct InstList {
    char *inst_;
    InstList *next_;
};

InstList *g_insts = nullptr;
InstList *g_insts_it = nullptr;

void FFF(void* value) {
    Entry *entry = (Entry*)value;
    if (!value)
        return;
    assert(entry->kind_ = Entry::VAR);
    assert(entry->u.var_.access_);
    assert(entry->u.var_.access_->frame_);
    dealloc_local(entry->u.var_.access_);
}

const char* op_str(ExpOp op) {
    /*enum ExpOp { NEGATIVE_OP, OR_OP, AND_OP, LT_OP,
    GT_OP, LE_OP, GE_OP, PLUS_OP, MINUS_OP, TIMES_OP, DIVIDE_OP,
    EQ_OP, NEQ_OP };*/
    switch (op) {
        case OR_OP:
            return "OR";
        case AND_OP:
            return "AND";
        case LT_OP:
            return "LT";
        case GT_OP:
            return "GT";
        case LE_OP:
            return "LE";
        case GE_OP:
            return "GE";
        case PLUS_OP:
            return "ADD";
        case MINUS_OP:
            return "SUB";
        case TIMES_OP:
            return "MPI";
        case DIVIDE_OP:
            return "DIV";
        default:
            assert(false);
    }
}

Symbol* make_new_label() {
    static int i = 0;
    i++;
    std::string s = "L"+std::to_string(i);
    return make_symbol(s.c_str());
}

TranslateLevel* make_new_level(TranslateLevel *parent) {
    TranslateLevel *ret = new TranslateLevel;
    ret->parent_ = parent;
    return ret;
}

InstList* insert_insts_list(char *inst) {
    if (!g_insts_it) {
        g_insts_it = new InstList;
        g_insts_it->inst_ = inst != nullptr ? strdup(inst) : inst;
        g_insts_it->next_ = nullptr;
        g_insts = g_insts_it;
    }
    else {
        g_insts_it->next_ = new InstList;
        g_insts_it->next_->inst_ = inst != nullptr ? strdup(inst) : inst;
        g_insts_it->next_->next_ = nullptr;
        g_insts_it = g_insts_it->next_;
    }
    return g_insts_it;
}

void dump_insts() {
    for (InstList* it = g_insts; it; it = it->next_) {
        printf("%s\n", it->inst_);
    }
}

TypeInfo* actural_type(TypeInfo *type) {
    if (type->kind_ == TypeInfo::NAMED) {
        return actural_type(type->u.named_.type_info_);
    }
    else {
        return type;
    }
}

bool TypeInfoEqual(TypeInfo *type1, TypeInfo *type2) {
    type1 = actural_type(type1);
    type2 = actural_type(type2);
    if (type1 == type2)
        return true;
    else if (type1->kind_ == TypeInfo::ARRAY && type2->kind_ == TypeInfo::ARRAY) {
        return TypeInfoEqual(type1->u.array_elem_, type2->u.array_elem_);
    }
    return false;
}
void access_local_or_global(Access* ac, bool flag/* false means value */);
SyntaxExpsList* params_list_reverse(SyntaxExpsList *exps);
TypeInfoList* param_types_list_reverse(TypeInfoList* tps);
void translate_exp(bool flag/* false means value */, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, SyntaxExp *exp, TranslateExp **out_tr_exp);
void translate_type_decl_stmts(TAB_table_ *type_env, SyntaxMoonStmtsList *stmts);
TypeInfo* translate_type(TAB_table_ *type_env, SyntaxType *syntax_type);
void pre_translate_func_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts);  /* handle function header so we can handle recursive function */
void translate_func_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts);      /* handle function body */
void translate_global_var_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts);

void translate1(TranslateLevel *level, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, Symbol *return_label, SyntaxMoonStmtsList *stmts);

TypeInfo* translate_left(bool flag/* false means value */, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, SyntaxLeftV *left, TranslateExp *out_tr_exp);

void translate(SyntaxMoonStmtsList *stmts) {
    S_table type_env = S_empty();
    S_table var_env = S_empty();

    S_enter(type_env, make_symbol(INT_TP), make_int_type_info());
    S_enter(type_env, make_symbol(STRING_TP), make_string_type_info());


    /*
     * global function declare
     * global variable declare
     * global struct   declare
     * global typedef
     * */
    assert(stmts);
    SyntaxMoonStmtsList *global_decl_type_stmts = nullptr, *it1 = nullptr;
    SyntaxMoonStmtsList *global_decl_var_stmts = nullptr, *it2 = nullptr;
    SyntaxMoonStmtsList *global_decl_func_stmts = nullptr, *it3 = nullptr;
    for (SyntaxMoonStmtsList *it = stmts; it != nullptr; it = it->next_) {
        SyntaxMoonStmt *stmt = it->stmt_;
        switch (stmt->stmt_kind_) {
            case SyntaxMoonStmt::DECL_TYPE_STMT:
            {
                if (it1 == nullptr) {
                    it1 = make_moon_stmts(stmt, nullptr);
                    global_decl_type_stmts = it1;
                }
                else {
                    it1->next_ = make_moon_stmts(stmt, nullptr);
                    it1 = it1->next_;
                }
            }
                break;
            case SyntaxMoonStmt::DECL_FUNC_STMT:
            {
                if (it3 == nullptr) {
                    it3 = make_moon_stmts(stmt, nullptr);
                    global_decl_func_stmts = it3;
                }
                else {
                    it3->next_ = make_moon_stmts(stmt, nullptr);
                    it3 = it3->next_;
                }
            }
                break;
            case SyntaxMoonStmt::DECL_VAR_STMT:
            {
                if (it2 == nullptr) {
                    it2 = make_moon_stmts(stmt, nullptr);
                    global_decl_var_stmts = it2;
                }
                else {
                    it2->next_ = make_moon_stmts(stmt, nullptr);
                    it2 = it2->next_;
                }
            }
                break;
            default:
            {
                assert(false);
            }
                break;
        }
    }

    translate_type_decl_stmts(type_env, global_decl_type_stmts);
    pre_translate_func_decl_stmts(type_env, var_env, global_decl_func_stmts);
    translate_global_var_decl_stmts(type_env, var_env, global_decl_var_stmts);
    translate_func_decl_stmts(type_env, var_env, global_decl_func_stmts);

    dump_insts();
    return;
}

void translate1(TranslateLevel *level, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, Symbol *return_label, SyntaxMoonStmtsList *stmts) {
    char buf[64] = { 0 };
    for (SyntaxMoonStmtsList *it = stmts; it != nullptr; it = it->next_) {
        SyntaxMoonStmt *stmt = it->stmt_;
        switch (stmt->stmt_kind_) {
            case SyntaxMoonStmt::DECL_VAR_STMT: {
                SyntaxType *syntax_type = stmt->u.decl_var_stmt_.var_type_;
                Symbol *var = stmt->u.decl_var_stmt_.var_;
                SyntaxExp *init_expr = stmt->u.decl_var_stmt_.init_expr_;
                TypeInfo *type = nullptr;
                if (!(type = translate_type(type_env, syntax_type))) {
                    assert(false);  /* undefined type error */
                }
                Entry *temp = (Entry*)S_look(var_env, var);
                if (temp) {
                    if (temp->kind_ == Entry::VAR) {
                        if (level == temp->u.var_.level_)
                            assert(false);  /* local variable redifinition error */
                    }
                    else {
                        assert(temp->kind_ == Entry::FUNC);
                        assert(false);  /* local variable cover global function error */
                    }
                }
                if (init_expr) {
                    TranslateExp* out_translate_exp = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, init_expr, &out_translate_exp);
                    assert(out_translate_exp && out_translate_exp->type_);
                    if (!TypeInfoEqual(type, out_translate_exp->type_)) {
                        assert(false);  /* Assign with type conflict error */
                    }
                }
                S_enter(var_env, var, make_var_entry(type, alloc_local(f), level));
                if (init_expr) {
                    Entry *entry = (Entry*)S_look(var_env, var);
                    assert(entry->kind_ == Entry::VAR);
                    access_local_or_global(entry->u.var_.access_, true);
                    sprintf(buf, "          %-5s", "STO");
                    insert_insts_list(buf);
                }
            } break;
            case SyntaxMoonStmt::IF_STMT: {
                char codestr[64] = { 0 };
                TranslateExp *out_translate_exp = nullptr;
                translate_exp(false, f, type_env, var_env, brk, stmt->u.if_stmt_.condition_, &out_translate_exp);
                Symbol *lab1 = make_new_label();
                Symbol *lab2 = nullptr;
                sprintf(codestr, "          %-5s%s", "CJMP", lab1->symbol_.c_str());
                insert_insts_list(codestr);
                S_beginScope(var_env);
                translate1(make_new_level(level), f, type_env, var_env, brk, return_label, stmt->u.if_stmt_.true_body_);
                S_endScope(var_env, FFF);
                if (stmt->u.if_stmt_.false_body_) {
                    lab2 = make_new_label();
                    sprintf(codestr, "          %-5s%s", "JMP", lab2->symbol_.c_str());
                    insert_insts_list(codestr);
                }
                sprintf(codestr, "%-5s%s :", "LAB", lab1->symbol_.c_str());
                insert_insts_list(codestr);
                if (stmt->u.if_stmt_.false_body_) {
                    S_beginScope(var_env);
                    translate1(make_new_level(level), f, type_env, var_env, brk, return_label, stmt->u.if_stmt_.false_body_);
                    S_endScope(var_env, FFF);
                    sprintf(codestr, "%-5s%s :", "LAB", lab2->symbol_.c_str());
                    insert_insts_list(codestr);
                }
            } break;
            case SyntaxMoonStmt::WHILE_STMT: {
                char codestr[64] = { 0 };
                Symbol *lab1 = make_new_label();
                sprintf(codestr, "%-5s%s :", "LAB", lab1->symbol_.c_str());
                insert_insts_list(codestr);
                TranslateExp *out_translate_exp = nullptr;
                translate_exp(false, f, type_env, var_env, brk, stmt->u.while_stmt_.condition_, &out_translate_exp);

                Symbol *lab2 = make_new_label();
                sprintf(codestr, "          %-5s%s", "CJMP", lab2->symbol_.c_str());
                insert_insts_list(codestr);
                S_beginScope(var_env);
                translate1(make_new_level(level), f, type_env, var_env, lab2, return_label, stmt->u.while_stmt_.while_body_);
                S_endScope(var_env, FFF);
                sprintf(codestr, "          %-5s%s", "JMP", lab1->symbol_.c_str());
                insert_insts_list(codestr);
                sprintf(codestr, "%-5s%s :", "LAB", lab2->symbol_.c_str());
                insert_insts_list(codestr);
            } break;
            case SyntaxMoonStmt::EXP_STMT: {
                TranslateExp *out_translate_exp = nullptr;
                translate_exp(false, f, type_env, var_env, brk, stmt->u.expr_, &out_translate_exp);
                /* currently, exp always has a value at top of stack, todo */
                sprintf(buf, "          %-5s%d", "DALC", 1);
                insert_insts_list(buf);
            } break;
            case SyntaxMoonStmt::RETURN_STMT: {
                TranslateExp *out_translate_exp = nullptr;
                translate_exp(false, f, type_env, var_env, brk, stmt->u.return_expr_, &out_translate_exp);
                assert(out_translate_exp && out_translate_exp->type_);
                if (!TypeInfoEqual(f->type_->u.func_proto.result_, out_translate_exp->type_)) {
                    assert(false);  /* return with type conflict error */
                }
                assert(!f->result_->frame_->is_global_);
                sprintf(buf, "          %-5s%d", "LOA", f->result_->offset_);
                insert_insts_list(buf);
                sprintf(buf, "          %-5s", "STO");
                insert_insts_list(buf);
                if (!return_label) {
                    assert(false);  /* internal error */
                }
                sprintf(buf, "          %-5s%s", "JMP", return_label->symbol_.c_str());
                insert_insts_list(buf);
            } break;
            case SyntaxMoonStmt::BREAK_STMT: {
                if (!brk) {
                    assert(false);  /* internal error */
                }
                sprintf(buf, "          %-5s%s", "JMP", brk->symbol_.c_str());
                insert_insts_list(buf);
            } break;
            default: {
                assert(false);  //DECL_TYPE_STMT, DECL_FUNC_STMT in function is not allowed
            }

        }
    }
}

void translate_exp(bool flag/* false means value */, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, SyntaxExp *syntax_exp, TranslateExp **out_tr_exp) {
    char buf[64] = { 0 };
    *out_tr_exp = new TranslateExp;
    TranslateExp *out_put = *out_tr_exp;
    out_put->type_ = nullptr;
    out_put->exp_ = nullptr;
    assert(syntax_exp);
    /*enum { INT_CONST, BOOL_CONST, STRING_CONST, LEFT_VALUE,
        FUNC_CALL, ASSIGN, OP_EXP, EXPR_LIST} kind_;*/
    switch (syntax_exp->kind_) {
        case SyntaxExp::INT_CONST: {
            sprintf(buf, "          %-5s%d", "LOC", syntax_exp->u.int_const_);
            insert_insts_list(buf);
            out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
        } break;
        case SyntaxExp::BOOL_CONST: {
            sprintf(buf, "          %-5s%d", "LOC", syntax_exp->u.bool_const_ ? 1 : 0);
            insert_insts_list(buf);
            out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
        } break;
        case SyntaxExp::STRING_CONST: {
            /* todo */
        } break;
        case SyntaxExp::LEFT_VALUE: {
            translate_left(flag, f, type_env, var_env, brk, syntax_exp->u.left_value_, out_put);
        } break;
        case SyntaxExp::FUNC_CALL: {
            Symbol *func = syntax_exp->u.func_call_.func_name_;
            SyntaxExpsList *params = syntax_exp->u.func_call_.real_params_in_;
            Entry *fun_type = (Entry*)S_look(var_env, func);
            if (!fun_type) {
                assert(false);  /* call undefined function */
            }
            else if (fun_type->kind_ != Entry::FUNC) {
                assert(false);  /* call not a function */
            }
            TypeInfoList *param_types = fun_type->u.func_.type_->u.func_proto.params_;
            sprintf(buf, "          %-5s%d", "ALC", 1);
            insert_insts_list(buf); // return value;
            /* params push in reverse order  */
            params = params_list_reverse(params);
            param_types = param_types_list_reverse(param_types);
            SyntaxExpsList *it_exp = nullptr;
            TypeInfoList *it_tp = nullptr;
            for (it_exp = params,it_tp = param_types; it_exp&&it_exp; it_exp = it_exp->next_, it_tp = it_tp->next_) {
                TranslateExp *tmp = nullptr;
                translate_exp(false, f, type_env, var_env, brk, it_exp->expr_, &tmp);
                if (!TypeInfoEqual(it_tp->type_info_, tmp->type_)) {
                    assert(false);  /* function call param type conflict error */
                }
            }
            if (it_exp || it_tp) {
                assert(false);  /* function call param count error */
            }
            sprintf(buf, "          %-5s%s", "CALL", fun_type->u.func_.label_->symbol_.c_str());
            insert_insts_list(buf);
            out_put->type_ = fun_type->u.func_.type_->u.func_proto.result_;
        } break;
        case SyntaxExp::ASSIGN: {
            TranslateExp *tmp1 = nullptr;
            translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.assign_exp_.expr_, &tmp1);
            TranslateExp *tmp = new TranslateExp;
            translate_left(true, f, type_env, var_env, brk, syntax_exp->u.assign_exp_.left_value_, tmp);
            if (!TypeInfoEqual(tmp->type_, tmp1->type_)) {
                assert(false);  /* Type conflict error */
            }
            sprintf(buf, "          %-5s", "STN");
            insert_insts_list(buf);
        } break;
        case SyntaxExp::OP_EXP: {
            /*enum ExpOp { NEGATIVE_OP, OR_OP, AND_OP, LT_OP,
                GT_OP, LE_OP, GE_OP, PLUS_OP, MINUS_OP, TIMES_OP, DIVIDE_OP,
                EQ_OP, NEQ_OP };*/
            switch (syntax_exp->u.op_exp_.exp_op_kind_) {
                case NEGATIVE_OP: {
                    sprintf(buf, "          %-5s%d", "LOC", 0);
                    insert_insts_list(buf);
                    TranslateExp *out_translate_exp = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.l_, &out_translate_exp);
                    if (actural_type(out_translate_exp->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  Arithmetic operator error */
                    }
                    sprintf(buf, "          %-5s", "SUB");
                    insert_insts_list(buf);
                    out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
                } break;
                case OR_OP: {
                    TranslateExp *l = nullptr, *r = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.l_, &l);
                    if (actural_type(l->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  Or operator error */
                    }
                    Symbol *lab1 = make_new_label();
                    sprintf(buf, "          %-5s%s", "CJMP", lab1->symbol_.c_str());
                    insert_insts_list(buf);
                    sprintf(buf, "          %-5s%d", "LOC", 1);
                    insert_insts_list(buf);
                    Symbol *lab2 = make_new_label();
                    sprintf(buf, "          %-5s%s", "JMP", lab2->symbol_.c_str());
                    insert_insts_list(buf);
                    sprintf(buf, "%-5s%s :", "LAB", lab1->symbol_.c_str());
                    insert_insts_list(buf);
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.r_, &r);
                    if (actural_type(r->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  Or operator error */
                    }
                    sprintf(buf, "%-5s%s :", "LAB", lab2->symbol_.c_str());
                    insert_insts_list(buf);
                    out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
                } break;
                case AND_OP: {
                    TranslateExp *l = nullptr, *r = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.l_, &l);
                    if (actural_type(l->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  And operator error */
                    }
                    Symbol *lab1 = make_new_label();
                    sprintf(buf, "          %-5s%s", "CJMP", lab1->symbol_.c_str());
                    insert_insts_list(buf);
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.r_, &r);
                    if (actural_type(r->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  Or operator error */
                    }
                    Symbol *lab2 = make_new_label();
                    sprintf(buf, "          %-5s%s", "JMP", lab2->symbol_.c_str());
                    insert_insts_list(buf);
                    sprintf(buf, "%-5s%s :", "LAB", lab1->symbol_.c_str());
                    insert_insts_list(buf);
                    sprintf(buf, "          %-5s%d", "LOC", 0);
                    insert_insts_list(buf);
                    sprintf(buf, "%-5s%s :", "LAB", lab2->symbol_.c_str());
                    insert_insts_list(buf);
                    out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
                } break;
                case LT_OP:
                case GT_OP:
                case LE_OP:
                case GE_OP:
                case PLUS_OP:
                case MINUS_OP:
                case TIMES_OP:
                case DIVIDE_OP: {
                    TranslateExp *l = nullptr, *r = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.l_, &l);
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.r_, &r);
                    if (actural_type(l->type_)->kind_ != TypeInfo::INT ||
                            actural_type(r->type_)->kind_ != TypeInfo::INT) {
                        assert(false);  /*  Arithmetic operator error */
                    }
                    sprintf(buf, "          %-5s", op_str(syntax_exp->u.op_exp_.exp_op_kind_));
                    insert_insts_list(buf);
                    out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
                } break;
                case EQ_OP:
                case NEQ_OP: {
                    TranslateExp *l = nullptr, *r = nullptr;
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.l_, &l);
                    translate_exp(false, f, type_env, var_env, brk, syntax_exp->u.op_exp_.r_, &r);
                    sprintf(buf, "          %-5s", op_str(syntax_exp->u.op_exp_.exp_op_kind_));
                    if (!TypeInfoEqual(l->type_, r->type_)) {
                        assert(false);  /*  ==, != use on different types error */
                    }
                    insert_insts_list(buf);
                    out_put->type_ = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
                } break;
                default:
                    assert(false); /* unreachable */
            }
        } break;
        case SyntaxExp::EXPR_LIST: {
            /* todo struct ctor, array stor */
        } break;
        default:
            assert(false);  /* unreachable */
    }
}

TypeInfo* translate_left(bool flag/* false means value */, Frame *f, TAB_table_ *type_env, TAB_table_ *var_env, Symbol *brk, SyntaxLeftV *left, TranslateExp *out_put) {
    char buf[64] = { 0 };
    switch (left->kind_) {
        case SyntaxLeftV::Simple: {
            Entry *entry = (Entry*)S_look(var_env, left->u.name_);
            if (!entry) {
                assert(false);  /* ref undefined variable error */
            }
            access_local_or_global(entry->u.var_.access_, flag);
            out_put->type_ = entry->u.var_.type_;
        } break;
        case SyntaxLeftV::ArrayIndex: {
            TranslateExp *tmp = new TranslateExp;
            translate_left(false, f, type_env, var_env, brk, left->u.array_index_.array_base_, tmp);
            if (actural_type(tmp->type_)->kind_ != TypeInfo::ARRAY) {
                assert(false);  /*  Subscript reference of non-array type error  */
            }
            TranslateExp *tmp1 = nullptr;
            translate_exp(false, f, type_env, var_env, brk, left->u.array_index_.index_expr_, &tmp1);
            if (actural_type(tmp1->type_)->kind_ != TypeInfo::INT) {
                assert(false);  /* Subscript reference of array type is not Integer error */
            }
            sprintf(buf, "          %-5s", "ADD");
            insert_insts_list(buf);
            if (!flag) {
                sprintf(buf, "          %-5s%d", "IND", 0);
                insert_insts_list(buf);
            }
            out_put->type_ = tmp->type_->u.array_elem_;
        } break;
        case SyntaxLeftV::StructField: {
            TranslateExp *tmp = new TranslateExp;
            translate_left(false, f, type_env, var_env, brk, left->u.struct_field_.struct_base_, tmp);
            if (actural_type(tmp->type_)->kind_ != TypeInfo::STRUCT) {
                assert(false);  /* field reference of non-struct type error */
            }
            int i = 0;
            TypeFieldTypeInfoList *it = nullptr;
            for (it = actural_type(tmp->type_)->u.struct_fields_type_, i = 0; it; it = it->next_,++i) {
                if (it->field_type_info_->field_ == left->u.struct_field_.field_name_) {
                    break;
                }
            }
            if (it == nullptr) {
                assert(false);  /* field reference of struct type not exist */
            }
            sprintf(buf, "          %-5s%d", "LOC", i);
            insert_insts_list(buf);
            sprintf(buf, "          %-5s", "ADD");
            insert_insts_list(buf);
            if (!flag) {
                sprintf(buf, "          %-5s%d", "IND", 0);
                insert_insts_list(buf);
            }
            out_put->type_ = it->field_type_info_->field_type_;
        } break;
        default:
            assert(false);  /* unreachable */
    }
    return nullptr;
}

void translate_type_decl_stmts(TAB_table_ *type_env, SyntaxMoonStmtsList *stmts) {
    // handle struct head first, so we can handle recursive struct
    for (SyntaxMoonStmtsList *it_stmts = stmts; it_stmts; it_stmts = it_stmts->next_)
    {
        SyntaxMoonStmt *stmt = it_stmts->stmt_;
        assert(stmt && stmt->stmt_kind_ == SyntaxMoonStmt::DECL_TYPE_STMT);
        switch (stmt->u.decl_type_stmt_.type_decl_kind_) {
            case SyntaxMoonStmt::STRUCT:
            {
                Symbol *struct_name = stmt->u.decl_type_stmt_.u.struct_.name_;
                if (S_look(type_env, struct_name) != nullptr) {
                    assert(false);  /*type redefinition error*/
                }
                S_enter(type_env, struct_name, make_named_type_info(struct_name, nullptr));
            }
                break;
            case SyntaxMoonStmt::TYPEDEF:
                break;
            default:
                assert(false);
        }
    }
    // handle struct definition
    for (SyntaxMoonStmtsList *it_stmts = stmts; it_stmts; it_stmts = it_stmts->next_)
    {
        SyntaxMoonStmt *stmt = it_stmts->stmt_;
        assert(stmt->stmt_kind_ == SyntaxMoonStmt::DECL_TYPE_STMT);
        switch (stmt->u.decl_type_stmt_.type_decl_kind_) {
            case SyntaxMoonStmt::STRUCT:
            {
                Symbol *struct_name = stmt->u.decl_type_stmt_.u.struct_.name_;
                SyntaxTypeFieldsList *type_fields = stmt->u.decl_type_stmt_.u.struct_.type_fields_;
                TypeFieldTypeInfoList *type_field_type_info_list = nullptr;
                TypeFieldTypeInfoList *head = nullptr;
                for (SyntaxTypeFieldsList *it = type_fields; it; it = it->next_) {
                    if (!type_field_type_info_list) {
                        type_field_type_info_list = make_field_type_info_list(
                                make_field_type_info(it->field_->var_, translate_type(type_env, it->field_->type_)), nullptr);
                        head = type_field_type_info_list;
                    }
                    else {
                        type_field_type_info_list->next_ = make_field_type_info_list(
                                make_field_type_info(it->field_->var_, translate_type(type_env, it->field_->type_)), nullptr);
                        type_field_type_info_list = type_field_type_info_list->next_;
                    }
                }
                TypeInfo *ty = (TypeInfo*)S_look(type_env, struct_name);
                assert(ty->kind_ == TypeInfo::NAMED);
                ty->u.named_.type_info_ = make_struct_type_info(head);
            }
                break;
            case SyntaxMoonStmt::TYPEDEF:
            {
                Symbol *struct_name = stmt->u.decl_type_stmt_.u.typedef_.name_;
                SyntaxType *syntax_type = stmt->u.decl_type_stmt_.u.typedef_.type_;
                if (S_look(type_env, struct_name) != nullptr) {
                    assert(false);  /*type redefinition error*/
                }
                S_enter(type_env, struct_name, translate_type(type_env, syntax_type));
            }
                break;
            default:
                assert(false);
        }
    }
}

TypeInfo* translate_type(TAB_table_ *type_env, SyntaxType *syntax_type) {
    assert(syntax_type);
    TypeInfo *ret = nullptr;
    switch (syntax_type->kind_) {
        case SyntaxType::INT:
        {
            ret = (TypeInfo*)S_look(type_env, make_symbol(INT_TP));
        }
            break;
        case SyntaxType::STRING:
        {
            ret = (TypeInfo*)S_look(type_env, make_symbol(STRING_TP));
        }
            break;
        case SyntaxType::ARRAY:
        {
            TypeInfo* elem = translate_type(type_env, syntax_type->u.array_type_.elem_type_);
            assert(elem);   /* undefined type error */
            ret = make_array_type_info(elem);
        }
            break;
        case SyntaxType::NAMED:
        {
            ret = (TypeInfo*)S_look(type_env, syntax_type->u.name_);
            assert(ret);    /* undefined type error */
        }
            break;
        case SyntaxType::VOID:
        {
            assert(false);  /* todo */
        }
            break;
        default:
            assert(false);  /* unreachable */
    }
    return ret;
}

void pre_translate_func_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts) {
    for (SyntaxMoonStmtsList *it_stmts = stmts; it_stmts; it_stmts = it_stmts->next_) {
        SyntaxMoonStmt *stmt = it_stmts->stmt_;
        assert(stmt && stmt->stmt_kind_ == SyntaxMoonStmt::DECL_FUNC_STMT);
        Symbol *func_name = stmt->u.decl_func_stmt.func_name_;
        if (S_look(var_env, func_name) != nullptr) {
            assert(false);  /* global function redefinition error */
        }
        SyntaxType *result_type = stmt->u.decl_func_stmt.result_type_;
        SyntaxTypeFieldsList *params_type_list = stmt->u.decl_func_stmt.params_type_;
        TypeInfoList *params_head = nullptr, *type_info_list = nullptr;
        for (SyntaxTypeFieldsList *it1 = params_type_list; it1; it1 = it1->next_) {
            if (type_info_list == nullptr) {
                type_info_list = make_type_info_list(translate_type(type_env, it1->field_->type_), nullptr);
                params_head = type_info_list;
            }
            else {
                type_info_list->next_ = make_type_info_list(translate_type(type_env, it1->field_->type_), nullptr);
                type_info_list = type_info_list->next_;
            }
        }
        TypeInfo *result = translate_type(type_env, result_type);
        S_enter(var_env, func_name, make_func_entry(make_func_type_info(result, nullptr, params_head), make_new_label()));
    }
}

void translate_func_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts) {
    char buf[64] = { 0 };
    for (SyntaxMoonStmtsList *it_stmts = stmts; it_stmts; it_stmts = it_stmts->next_) {
        SyntaxMoonStmt *stmt = it_stmts->stmt_;
        assert(stmt && stmt->stmt_kind_ == SyntaxMoonStmt::DECL_FUNC_STMT);
        Symbol *func_name = stmt->u.decl_func_stmt.func_name_;
        Entry *fun_entry = (Entry*)S_look(var_env, func_name);
        assert(fun_entry->kind_ == Entry::FUNC);
        S_beginScope(var_env);
        Symbol *label = fun_entry->u.func_.label_;
        sprintf(buf, "%-5s%s :", "FLAB", label->symbol_.c_str());
        insert_insts_list(buf);
        char **patch = &(insert_insts_list(nullptr)->inst_);

        SyntaxTypeFieldsList *it1 = nullptr;
        AccessList *it2 = nullptr;
        TypeInfoList *it3 = nullptr;
        for (it1 = stmt->u.decl_func_stmt.params_type_,
                it2 = fun_entry->u.func_.frame_->access_list_,
                it3 = fun_entry->u.func_.type_->u.func_proto.params_;
                                it1 && it2; it1 = it1->next_, it2 = it2->next_, it3 = it3->next_) {
            S_enter(var_env, it1->field_->var_, make_var_entry(it3->type_info_, it2->access_, make_new_level(nullptr)));
        }
        if (it1 || it2 || it3) {
            assert(false);  /* internal error */
        }
        Symbol *ret = make_new_label();
        translate1(make_new_level(nullptr), fun_entry->u.func_.frame_, type_env, var_env, nullptr, ret, stmt->u.decl_func_stmt.func_body_);
        sprintf(buf, "          %-5s%d", "ALC", fun_entry->u.func_.frame_->max_local_count_);
        *patch = strdup(buf);
        sprintf(buf, "%-5s%s :", "LAB", ret->symbol_.c_str());
        insert_insts_list(buf);
        sprintf(buf, "          %-5s", "RET");
        insert_insts_list(buf);
        S_endScope(var_env, FFF);
    }
}

void translate_global_var_decl_stmts(TAB_table_ *type_env, TAB_table_ *var_env, SyntaxMoonStmtsList *stmts) {
    if (!stmts) return;
    char buf[64] = { 0 };
    Frame *global_frame = make_global_frame();
    char **patch = &(insert_insts_list(nullptr)->inst_);
    for (SyntaxMoonStmtsList *it_stmts = stmts; it_stmts; it_stmts = it_stmts->next_) {
        SyntaxMoonStmt *stmt = it_stmts->stmt_;
        assert(stmt && stmt->stmt_kind_ == SyntaxMoonStmt::DECL_VAR_STMT);
        SyntaxType *syntax_type = stmt->u.decl_var_stmt_.var_type_;
        Symbol *var = stmt->u.decl_var_stmt_.var_;
        SyntaxExp *init_expr = stmt->u.decl_var_stmt_.init_expr_;
        TypeInfo *type = nullptr;
        if (!(type = translate_type(type_env, syntax_type))) {
            assert(false);  /* undefined type error */
        }
        if (S_look(var_env, var) != nullptr) {
            assert(false);  /* global variable redefinition error */
        }
        if (init_expr) {
            TranslateExp* out_translate_exp = nullptr;
            translate_exp(false, global_frame, type_env, var_env, nullptr, init_expr, &out_translate_exp);
            assert(out_translate_exp && out_translate_exp->type_);
            if (!TypeInfoEqual(type, out_translate_exp->type_)) {
                assert(false);  /*  Type conflict error */
            }
        }
        S_enter(var_env, var, make_var_entry(type, alloc_local(global_frame), nullptr));
        if (init_expr) {
            Entry * entry = (Entry*)S_look(var_env, var);
            assert(entry && entry->kind_ == Entry::VAR);
            access_local_or_global(entry->u.var_.access_, true);
            sprintf(buf, "          %-5s", "STO");
            insert_insts_list(buf);
        }
    }
    sprintf(buf, "          %-5s%d", "ALC", global_frame->max_local_count_);
    *patch = strdup(buf);
}

SyntaxExpsList* params_list_reverse(SyntaxExpsList *exps) {
    if (!exps)
        return nullptr;
    SyntaxExpsList *ret_it = nullptr;
    for (SyntaxExpsList *it = exps; it; it = it->next_) {
        ret_it = make_expr_list(it->expr_, ret_it);
    }
    return ret_it;
}

TypeInfoList* param_types_list_reverse(TypeInfoList* tps) {
    if (!tps)
        return nullptr;
    TypeInfoList *ret_it = nullptr;
    for (TypeInfoList *it = tps; it; it = it->next_) {
        ret_it = make_type_info_list(it->type_info_, ret_it);
    }
    return ret_it;
}

void access_local_or_global(Access* ac, bool flag/* false means value */) {
    char buf[64] = { 0 };
    if (ac->frame_->is_global_) {
        sprintf(buf, "          %-5s%d", "LOC", STACK_BOTTOM + ac->offset_);
        insert_insts_list(buf);
        if (!flag) {
            sprintf(buf, "          %-5s", "IND");
        }
    }
    else {
        if (flag) {
            sprintf(buf, "          %-5s%d", "LOA", ac->offset_);
            insert_insts_list(buf);
        }
        else {
            sprintf(buf, "          %-5s%d", "LOV", ac->offset_);
            insert_insts_list(buf);
        }
    }
}

/*
 * todo
 *  variable parameters  inner function:
 *     array_address array_ctor(int cnt, ...)       invisible
 *     struct_address struct_ctor(int cnt, ...)     invisible
 *     int array_length(T[] t)                      visible
 *     int print(T t)                               visible
 *     ...
 *  AND OR operator
 *     ...
 *  break stmt
 *  moon virtual machine, design moon instruction byte code
 * */
