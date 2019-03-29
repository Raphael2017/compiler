#include "syntax_tree.h"
#include "utils.h"
#include <assert.h>

SyntaxMoonStmtsList* make_moon_stmts(SyntaxMoonStmt *stmt, SyntaxMoonStmtsList* stmts) {
    SyntaxMoonStmtsList *ret = new SyntaxMoonStmtsList;
    ret->stmt_ = stmt;
    ret->next_ = stmts;
    assert(ret->stmt_);
    return ret;
}

SyntaxMoonStmt* make_decl_var_stmt(SyntaxType *type, Symbol *sym, SyntaxExp *init_exp) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::DECL_VAR_STMT;
    ret->u.decl_var_stmt_.var_type_ = type;
    ret->u.decl_var_stmt_.var_ = sym;
    ret->u.decl_var_stmt_.init_expr_ = init_exp;
    return ret;
}

SyntaxMoonStmt* make_decl_type_struct_stmt(SyntaxTypeFieldsList *record, Symbol *sym) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::DECL_TYPE_STMT;
    ret->u.decl_type_stmt_.type_decl_kind_ = SyntaxMoonStmt::STRUCT;
    ret->u.decl_type_stmt_.u.struct_.type_fields_ = record;
    ret->u.decl_type_stmt_.u.struct_.name_ = sym;
    return ret;
}

SyntaxMoonStmt* make_decl_type_typedef_stmt(SyntaxType *type, Symbol *sym) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::DECL_TYPE_STMT;
    ret->u.decl_type_stmt_.type_decl_kind_ = SyntaxMoonStmt::TYPEDEF;
    ret->u.decl_type_stmt_.u.typedef_.type_ = type;
    ret->u.decl_type_stmt_.u.typedef_.name_ = sym;
    return ret;
}

SyntaxTypeFieldsList* make_type_fields(SyntaxTypeField *type_field, SyntaxTypeFieldsList * type_fields_list) {
    SyntaxTypeFieldsList *ret = new SyntaxTypeFieldsList;
    ret->field_ = type_field;
    ret->next_ = type_fields_list;
    return ret;
}

SyntaxMoonStmt* make_decl_func_stmt(SyntaxType *type, Symbol *func_name, SyntaxTypeFieldsList * params, SyntaxMoonStmtsList *body) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::DECL_FUNC_STMT;
    ret->u.decl_func_stmt.result_type_ = type;
    ret->u.decl_func_stmt.func_name_ = func_name;
    ret->u.decl_func_stmt.params_type_ = params;
    ret->u.decl_func_stmt.func_body_ = body;
    return ret;
}

SyntaxMoonStmt* make_if_stmt(SyntaxExp *condition, SyntaxMoonStmtsList *true_body, SyntaxMoonStmtsList *false_body) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::IF_STMT;
    ret->u.if_stmt_.condition_ = condition;
    ret->u.if_stmt_.true_body_ = true_body;
    ret->u.if_stmt_.false_body_ = false_body;
    return ret;
}

SyntaxMoonStmt* make_while_stmt(SyntaxExp *condition, SyntaxMoonStmtsList *body) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::WHILE_STMT;
    ret->u.while_stmt_.condition_ = condition;
    ret->u.while_stmt_.while_body_ = body;
    return ret;
}

SyntaxMoonStmt* make_exp_stmt(SyntaxExp *exp) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::EXP_STMT;
    ret->u.expr_ = exp;
    return ret;
}

SyntaxMoonStmt* make_return_stmt(SyntaxExp *expr) {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::RETURN_STMT;
    ret->u.return_expr_ = expr;
    return ret;
}

SyntaxMoonStmt* make_break_stmt() {
    SyntaxMoonStmt *ret = new SyntaxMoonStmt;
    ret->stmt_kind_ = SyntaxMoonStmt::BREAK_STMT;
    return ret;
}

SyntaxLeftV* make_simple_left_value(Symbol *sym) {
    SyntaxLeftV *ret = new SyntaxLeftV;
    ret->kind_ = SyntaxLeftV::Simple;
    ret->u.name_ = sym;
    return ret;
}

SyntaxLeftV* make_struct_field_left_value(SyntaxLeftV *lv, Symbol *sym) {
    SyntaxLeftV *ret = new SyntaxLeftV;
    ret->kind_ = SyntaxLeftV::StructField;
    ret->u.struct_field_.struct_base_ = lv;
    ret->u.struct_field_.field_name_ = sym;
    return ret;
}

SyntaxLeftV* make_array_index_left_value(SyntaxLeftV *lv, SyntaxExp *index) {
    SyntaxLeftV *ret = new SyntaxLeftV;
    ret->kind_ = SyntaxLeftV::ArrayIndex;
    ret->u.array_index_.array_base_ = lv;
    ret->u.array_index_.index_expr_ = index;
    return ret;
}

SyntaxTypeField* make_type_field(SyntaxType *type, Symbol *sym) {
    SyntaxTypeField *ret = new SyntaxTypeField;
    ret->type_ = type;
    ret->var_ = sym;
    return ret;
}

SyntaxType* make_int_type() {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::INT;
    return ret;
}

SyntaxType* make_string_type() {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::STRING;
    return ret;
}

SyntaxType* make_void_type() {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::VOID;
    return ret;
}

SyntaxType* make_named_type(Symbol *sym) {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::NAMED;
    ret->u.name_ = sym;
    return ret;
}

SyntaxType* make_int_arr_type(SyntaxExp *size) {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::ARRAY;
    ret->u.array_type_.elem_type_ = make_int_type();
    ret->u.array_type_.size_ = size;
    return ret;
}

SyntaxType* make_named_arr_type(Symbol *sym, SyntaxExp *size) {
    SyntaxType *ret = new SyntaxType;
    ret->kind_ = SyntaxType::ARRAY;
    ret->u.array_type_.elem_type_ = make_named_type(sym);
    ret->u.array_type_.size_ = size;
    return ret;
}

SyntaxExp* make_expr_int_const(int i) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::INT_CONST;
    ret->u.int_const_ = i;
    return ret;
}

SyntaxExp* make_expr_nil_const() {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::NIL_CONST;
    return ret;
}

SyntaxExp* make_expr_bool_const(bool b) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::BOOL_CONST;
    ret->u.bool_const_ = b;
    return ret;
}

SyntaxExp* make_expr_str_const(char *str) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::STRING_CONST;
    ret->u.string_const_ = str;
    return ret;
}

SyntaxExp* make_expr_left_value(SyntaxLeftV *left) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::LEFT_VALUE;
    ret->u.left_value_ = left;
    return ret;
}

SyntaxExp* make_expr_func_call(Symbol *func, SyntaxExpsList *params) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::FUNC_CALL;
    ret->u.func_call_.func_name_ = func;
    ret->u.func_call_.real_params_in_ = params;
    return ret;
}

SyntaxExp* make_expr_assign(SyntaxLeftV *lv, SyntaxExp *exp) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::ASSIGN;
    ret->u.assign_exp_.left_value_ = lv;
    ret->u.assign_exp_.expr_ = exp;
    return ret;
}

SyntaxExp* make_expr_op(ExpOp exp_op, SyntaxExp *l, SyntaxExp *r) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::OP_EXP;
    ret->u.op_exp_.exp_op_kind_ = exp_op;
    ret->u.op_exp_.l_ = l;
    ret->u.op_exp_.r_ = r;
    return ret;
}

SyntaxExp* make_expr_struct_array_init(SyntaxExpsList *expr_list, SyntaxType *tp) {
    SyntaxExp *ret = new SyntaxExp;
    ret->kind_ = SyntaxExp::EXPR_LIST;
    ret->u.struct_array_init_.expr_list_ = expr_list;
    ret->u.struct_array_init_.type_ = tp;
    return ret;
}


SyntaxExpsList* make_expr_list(SyntaxExp *expr, SyntaxExpsList *expr_list) {
    SyntaxExpsList *ret = new SyntaxExpsList;
    ret->expr_ = expr;
    ret->next_ = expr_list;
    return ret;
}

Symbol* make_symbol(const char* str) {
    static const size_t syms_hash_tbl_size = 109;
    static Symbol *syms_hash_tbl[syms_hash_tbl_size] = { 0 };

    uint64_t hash = utils::hash(str);
    size_t index = hash % syms_hash_tbl_size;


    for (Symbol* sym = syms_hash_tbl[index]; sym; sym = sym->next_)
        if (sym->symbol_ == str)
            return sym;

    Symbol *ret = new Symbol;
    ret->symbol_ = str;
    ret->next_ = syms_hash_tbl[index];
    syms_hash_tbl[index] = ret;
    return ret;
}

void accept(SyntaxMoonStmtsList* stmts, ParseResult* result) {
    assert(stmts->stmt_);
    result->accept = true;
    result->moon_stmts_list_ = stmts;
    assert(result->moon_stmts_list_->stmt_);
}

