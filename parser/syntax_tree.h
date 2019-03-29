#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include <string>
#include <sstream>
struct SyntaxMoonStmt;

struct SyntaxMoonStmtsList{
    SyntaxMoonStmt *stmt_;
    SyntaxMoonStmtsList *next_;
};

struct SyntaxType; struct SyntaxExp; struct Symbol;

struct SyntaxTypeField {
    SyntaxType *type_;
    Symbol *var_;
};

struct SyntaxTypeFieldsList {
    SyntaxTypeField *field_;
    SyntaxTypeFieldsList *next_;
};

struct SyntaxMoonStmt {
    enum TypeDecl { TYPEDEF, STRUCT };
    enum { DECL_VAR_STMT, DECL_TYPE_STMT,
            DECL_FUNC_STMT,IF_STMT, WHILE_STMT,
            EXP_STMT, RETURN_STMT,BREAK_STMT} stmt_kind_;
    union {
        struct {
            SyntaxType *var_type_;
            Symbol *var_;
            SyntaxExp *init_expr_;
        } decl_var_stmt_;

        struct {
            TypeDecl type_decl_kind_;
            union {
               struct {
                   SyntaxType *type_;
                   Symbol *name_;
               } typedef_;
               struct {
                   SyntaxTypeFieldsList *type_fields_;
                   Symbol *name_;
               } struct_;
            } u;
        } decl_type_stmt_;

        struct {
            SyntaxType *result_type_;
            Symbol *func_name_;
            SyntaxTypeFieldsList *params_type_;
            SyntaxMoonStmtsList *func_body_;
        } decl_func_stmt;

        struct {
            SyntaxExp *condition_;
            SyntaxMoonStmtsList *true_body_;
            SyntaxMoonStmtsList *false_body_;   /* nil means no else */
        } if_stmt_;

        struct {
            SyntaxExp *condition_;
            SyntaxMoonStmtsList *while_body_;
        } while_stmt_;
        SyntaxExp *expr_;
        SyntaxExp *return_expr_;
    } u;
};

struct SyntaxType {
    enum { VOID, INT, STRING, ARRAY, NAMED } kind_;
    union {
        struct {
            SyntaxType *elem_type_;
            SyntaxExp *size_;
        } array_type_;
        Symbol *name_;
    } u;
};

struct SyntaxExp;

struct SyntaxLeftV{
    enum { Simple, StructField, ArrayIndex } kind_;
    union {
        Symbol *name_;
        struct {
            Symbol *field_name_;
            SyntaxLeftV *struct_base_;
        } struct_field_;
        struct {
            SyntaxExp *index_expr_;
            SyntaxLeftV *array_base_;
        } array_index_;
    } u;
};

struct SyntaxExpsList{
    SyntaxExp *expr_;
    SyntaxExpsList *next_;
};

enum ExpOp { NEGATIVE_OP, OR_OP, AND_OP, LT_OP,
    GT_OP, LE_OP, GE_OP, PLUS_OP, MINUS_OP, TIMES_OP, DIVIDE_OP,
    EQ_OP, NEQ_OP };

struct SyntaxExp {
    enum { NIL_CONST, INT_CONST, BOOL_CONST, STRING_CONST, LEFT_VALUE,
            FUNC_CALL, ASSIGN, OP_EXP, EXPR_LIST} kind_;
    union {
        int int_const_;
        bool bool_const_;
        char *string_const_;
        SyntaxLeftV *left_value_;
        struct {
            Symbol *func_name_;
            SyntaxExpsList *real_params_in_;
        } func_call_;
        struct {
            ExpOp exp_op_kind_;
            SyntaxExp *l_;
            SyntaxExp *r_;
        } op_exp_;
        struct {
            SyntaxLeftV *left_value_;
            SyntaxExp *expr_;
        } assign_exp_;
        struct {
            SyntaxExpsList *expr_list_;
            SyntaxType *type_;
        } struct_array_init_;
    } u;
};

struct Symbol {
    std::string symbol_;
    Symbol *next_;
};

struct ParseResult {
    SyntaxMoonStmtsList *moon_stmts_list_{0};
    bool accept{false};
    int errFirstLine{0};
    int errFirstColumn{0};
    std::string errDetail;
    std::stringstream buf_;
};

#ifndef YYtypeDEF_YY_SCANNER_T
#define YYtypeDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif


SyntaxMoonStmtsList* make_moon_stmts(SyntaxMoonStmt *stmt, SyntaxMoonStmtsList* stmts);

SyntaxMoonStmt* make_decl_var_stmt(SyntaxType *type, Symbol *sym, SyntaxExp *init_exp);

SyntaxMoonStmt* make_decl_type_struct_stmt(SyntaxTypeFieldsList *record, Symbol *sym);

SyntaxMoonStmt* make_decl_type_typedef_stmt(SyntaxType *type, Symbol *sym);

SyntaxTypeFieldsList* make_type_fields(SyntaxTypeField *type_field, SyntaxTypeFieldsList * type_fields_list);

SyntaxMoonStmt* make_decl_func_stmt(SyntaxType *type, Symbol *func_name, SyntaxTypeFieldsList * params, SyntaxMoonStmtsList *body);

SyntaxMoonStmt* make_if_stmt(SyntaxExp *condition, SyntaxMoonStmtsList *true_body, SyntaxMoonStmtsList *false_body);

SyntaxMoonStmt* make_while_stmt(SyntaxExp *condition, SyntaxMoonStmtsList *body);

SyntaxMoonStmt* make_exp_stmt(SyntaxExp *exp);

SyntaxMoonStmt* make_return_stmt(SyntaxExp *expr);

SyntaxMoonStmt* make_break_stmt();

SyntaxLeftV* make_simple_left_value(Symbol *sym);

SyntaxLeftV* make_struct_field_left_value(SyntaxLeftV *lv, Symbol *sym);

SyntaxLeftV* make_array_index_left_value(SyntaxLeftV *lv, SyntaxExp *index);

SyntaxTypeField* make_type_field(SyntaxType *type, Symbol *sym);

SyntaxType* make_int_type();

SyntaxType* make_string_type();

SyntaxType* make_void_type();

SyntaxType* make_named_type(Symbol *sym);

SyntaxType* make_int_arr_type(SyntaxExp *size);

SyntaxType* make_named_arr_type(Symbol *sym, SyntaxExp *size);

SyntaxExp* make_expr_int_const(int i);

SyntaxExp* make_expr_nil_const();

SyntaxExp* make_expr_bool_const(bool b);

SyntaxExp* make_expr_str_const(char *str);

SyntaxExp* make_expr_left_value(SyntaxLeftV *left);

SyntaxExp* make_expr_func_call(Symbol *func, SyntaxExpsList *params);

SyntaxExp* make_expr_assign(SyntaxLeftV *lv, SyntaxExp *exp);

SyntaxExp* make_expr_op(ExpOp exp_op, SyntaxExp *l, SyntaxExp *r);

SyntaxExp* make_expr_struct_array_init(SyntaxExpsList *expr_list, SyntaxType *type);

SyntaxExpsList* make_expr_list(SyntaxExp *expr, SyntaxExpsList *expr_list);

Symbol* make_symbol(const char* str);

void accept(SyntaxMoonStmtsList* stmts, ParseResult* result);

#endif