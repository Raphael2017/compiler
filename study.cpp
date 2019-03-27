#include <stdio.h>
#include <assert.h>
#include "syntax_tree.h"
#define CODE_SIZE 64

typedef enum { ExpKind, IfKind, WhileKind, BreakKind, OtherKind } NodeKind;
typedef struct StreeNode_
{
    StreeNode_(NodeKind kd,
            StreeNode_* c1, StreeNode_* c2, StreeNode_* c3,
            int v) : kind(kd), child{c1,c2,c3}, val(v) {}
    NodeKind kind;
    StreeNode_* child[3];
    int val;
} StreeNode, *PStreeNode, *SyntaxTree;

char* gen_label();
void emit_code(const char*);
void gen_code(SyntaxTree,const char*);

int mai1n()
{
    bool a = false || true && false;
    PStreeNode if1 = new StreeNode(
            IfKind,
            new StreeNode(ExpKind, nullptr, nullptr, nullptr, 0),
            new StreeNode(BreakKind, nullptr, nullptr, nullptr, 0),
            new StreeNode(OtherKind, nullptr, nullptr, nullptr, 0),
            0
            );
    PStreeNode wl = new StreeNode(
            WhileKind,
            new StreeNode(ExpKind, nullptr, nullptr, nullptr, 1),
            if1,
            nullptr,
            0
            );
    PStreeNode if2 = new StreeNode(
            IfKind,
            new StreeNode(ExpKind, nullptr, nullptr, nullptr, 1),
            wl,
            nullptr,
            0
            );
    gen_code(if2, "");
    return 0;
}

char* gen_label()
{
    static int L = 0;
    ++L;
    assert(L < 100);
    char* ret = new char[4];
    sprintf(ret, "L%d", L);
    return ret;
}

void emit_code(const char* inst)
{
    printf("%s\n", inst);
}

void gen_code(SyntaxTree t,const char *label)
{
    char codestr[CODE_SIZE] = { 0 };
    if (!t) return;
    switch (t->kind)
    {
        case ExpKind:
            if (t->val == 0) emit_code("ldc false");
            else emit_code("ldc true");
            break;
        case IfKind:
        {
            gen_code(t->child[0], label);
            char* lab1 = gen_label();
            char* lab2;
            sprintf(codestr, "%s %s", "fjp", lab1);
            emit_code(codestr);
            gen_code(t->child[1], label);
            if (t->child[2])
            {
                lab2 = gen_label();
                sprintf(codestr, "%s %s", "ujp", lab2);
                emit_code(codestr);
            }
            sprintf(codestr, "%s %s", "lab", lab1);
            emit_code(codestr);
            if (t->child[2])
            {
                gen_code(t->child[2], label);
                sprintf(codestr, "%s %s", "lab", lab2);
                emit_code(codestr);
            }
        }
            break;
        case WhileKind:
        {
            char* lab1 = gen_label();
            sprintf(codestr, "%s %s", "lab", lab1);
            emit_code(codestr);
            gen_code(t->child[0], label);
            char* lab2 = gen_label();
            sprintf(codestr, "%s %s", "fjp", lab2);
            emit_code(codestr);
            gen_code(t->child[1], lab2);
            sprintf(codestr, "%s %s", "ujp", lab1);
            emit_code(codestr);
            sprintf(codestr, "%s %s", "lab", lab2);
            emit_code(codestr);
        }
            break;
        case BreakKind:
        {
            sprintf(codestr, "%s %s", "ujp", label);
            emit_code(codestr);
        }
            break;
        case OtherKind:
        {
            emit_code("OTHER");
        }
            break;
        default:
            assert(false);  /* unreachable */
    }
}

namespace study
{
    // Syntax tree
    enum OP{ ASSIGN = '=',
            PLUS = '+',
            MINUS = '-',
            MUL = '*',
            DIV = '/',
            GREATER = '>',
            LESS = '<',
            AND = '&',
            OR = '|',
            SubScript = '[',        //l_[r_]
            VARREF = 10000,
            CONSTANT };
    struct SynNode
    {
        OP op_;
        union {
            struct {
                SynNode* l_;
                SynNode* r_;
            } operands_;
            const char* var_;
            int constant_;
        } u;
    };

    // Type info
    struct Symbol;
    struct TypeInfo;
    struct TypeField
    {
        Symbol *name_;
        TypeInfo *info_;
    };
    struct TypeFieldList
    {
        TypeField head;
        TypeFieldList* next_;
    };
    struct TypeList
    {
        TypeInfo *head_;
        TypeFieldList *next_;
    };
    struct TypeInfo{
        enum {Ty_Int, Ty_Array, Ty_Struct, Ty_Named_Type, Ty_Function, Ty_Void} kind_;
        union {
            TypeInfo *array_element_;
            TypeFieldList *struct_fields_;
            struct{
                Symbol *name_;
                TypeInfo *type_;
            } named_struct_;
            struct {
                TypeList *params_;
                TypeInfo *result_;
            } prototype_;
        } u;
    };


    SynNode* new_ref(const char* str) { SynNode *ret = new SynNode; ret->op_ = VARREF; ret->u.var_ = str; return ret; }
    SynNode* new_constant(int n)      { SynNode *ret = new SynNode; ret->op_ = CONSTANT; ret->u.constant_ = n; return ret; }
    SynNode* new_op(OP op, SynNode *l, SynNode *r) { SynNode *ret = new SynNode; ret->op_ = op; ret->u.operands_.l_ = l; ret->u.operands_.r_ = r; return ret; }

    void trans_exp(SynNode* exp, bool flag/* false means address true means *address */, bool flag2/* true means need return a value */)
    {
        char codestr[CODE_SIZE] = { 0 };
        switch (exp->op_)
        {
            case ASSIGN:
            {
                assert(exp->u.operands_.l_ &&
                       (exp->u.operands_.l_->op_ == VARREF ||
                        exp->u.operands_.l_->op_ == SubScript));
                trans_exp(exp->u.operands_.r_, true, true);
                trans_exp(exp->u.operands_.l_, false, true);
                if (!flag2)
                    sprintf(codestr, "%-27s", "STORE");
                else
                    sprintf(codestr, "%-27s", "STORE_NO");
                emit_code(codestr);
            }
                break;
            case GREATER:
            case LESS:
            case PLUS:
            case MINUS:
            case MUL:
            case DIV:
            {
                assert(exp->u.operands_.l_ && exp->u.operands_.r_);
                trans_exp(exp->u.operands_.l_, true, true);
                trans_exp(exp->u.operands_.r_, true, true);
                sprintf(codestr, "%-27s%c","INTEGER_BINARY_OPERATION", exp->op_);
                emit_code(codestr);
            }
                break;
            case VARREF:
            {
                if (flag)
                {
                    sprintf(codestr, "%-27s%s0", "LOAD_VARIABLE", exp->u.var_);
                    emit_code(codestr);
                }
                else
                {
                    sprintf(codestr, "%-27s%s0", "LOAD_ADDRESS", exp->u.var_);
                    emit_code(codestr);
                }
            }
                break;
            case SubScript:
            {
                trans_exp(exp->u.operands_.l_, false, true);    // load base address
                sprintf(codestr, "%-27s%d", "LOAD_CONSTANT", 1/* size of type*/); // todo need typeinfo with typesize
                emit_code(codestr);
                trans_exp(exp->u.operands_.r_, true, true);
                sprintf(codestr, "%-27s%c", "INTEGER_BINARY_OPERATION", '*');
                emit_code(codestr);
                sprintf(codestr, "%-27s%c", "INTEGER_BINARY_OPERATION", '+');
                emit_code(codestr);
                if (flag)
                {
                    sprintf(codestr, "%-27s%d", "INDIRECT_LOAD", 0);
                    emit_code(codestr);
                }
            }
                break;
            case CONSTANT:
            {
                sprintf(codestr, "%-27s%d", "LOAD_CONSTANT", exp->u.constant_);
                emit_code(codestr);
            }
                break;
            case AND:// Logic short circuit
            {
                trans_exp(exp->u.operands_.l_, true, true);
                char* lab1 = gen_label();
                sprintf(codestr, "%-27s%s", "CONDITION_JUMP", lab1);
                emit_code(codestr);
                trans_exp(exp->u.operands_.r_, true, true);
                char* lab2 = gen_label();
                sprintf(codestr, "%-27s%s", "JUMP", lab2);
                emit_code(codestr);
                sprintf(codestr, "%-27s%s", "LABEL", lab1);
                emit_code(codestr);
                sprintf(codestr, "%-27s%d", "LOAD_CONSTANT", 0);
                emit_code(codestr);
                sprintf(codestr, "%-27s%s", "LABEL", lab2);
                emit_code(codestr);
            }
                break;
            case OR:// Logic short circuit
            {
                trans_exp(exp->u.operands_.l_, true, true);
                char* lab1 = gen_label();
                sprintf(codestr, "%-27s%s", "CONDITION_JUMP", lab1);
                emit_code(codestr);
                sprintf(codestr, "%-27s%d", "LOAD_CONSTANT", 1);
                emit_code(codestr);
                char* lab2 = gen_label();
                sprintf(codestr, "%-27s%s", "JUMP", lab2);
                emit_code(codestr);
                sprintf(codestr, "%-27s%s", "LABEL", lab1);
                emit_code(codestr);
                trans_exp(exp->u.operands_.r_, true, true);
                sprintf(codestr, "%-27s%s", "LABEL", lab2);
                emit_code(codestr);
            }
                break;
            default:
                assert(false);
        }
    }

    void test()
    {
        /*
         * d = (x * (y-z))/(d-i=(i+1)) +1;
         *
         *                  +
         *               /      \
         *              #        1
         *           /     \
         *          *       -
         *         / \     / \
         *        x   -   d    =
         *           / \      / \
         *          y   z    i   +
         *                      / \
         *                     i   1
         *
         * */
        SynNode *root = new_op(ASSIGN, new_ref("d"), new_op(PLUS,
                                                            new_op(DIV,
                                                                   new_op(MUL, new_ref("x"),
                                                                          new_op(MINUS,
                                                                                 new_ref("y"),
                                                                                 new_ref("z"))),
                                                                   new_op(MINUS, new_ref("d"),
                                                                          new_op(ASSIGN, new_ref("i"),
                                                                                 new_op(PLUS, new_ref("i"), new_constant(1))))), new_constant(1)));
        trans_exp(root, true, false);
    }

    void test1()
    {
        // a = (m>3) || (m<n) && (m<(m*n));
        SynNode *root = new_op(ASSIGN,
                new_ref("a"),
                new_op(OR, new_op(GREATER, new_ref("m"), new_constant(3)), new_op(AND, new_op(LESS, new_ref("m"), new_ref("n")),
                        new_op(LESS, new_ref("m"), new_op(MUL, new_ref("m"),new_ref("n"))))));
        trans_exp(root, true, false);
    }

    void test2()
    {
        // a = m && n;
        SynNode *root = new_op(ASSIGN, new_ref("a"), new_op(AND, new_ref("m"), new_ref("n")));
        trans_exp(root, true, false);
    }

    void test3()
    {
        // a[i] = (a[i+j]=1) - a[j-1]
        SynNode *root = new_op(ASSIGN, new_op(SubScript, new_ref("a"), new_ref("i")), new_op(MINUS, new_op(ASSIGN, new_op(SubScript, new_ref("a"), new_op(PLUS, new_ref("i"), new_ref("j"))), new_constant(1)),
                new_op(SubScript, new_ref("a"), new_op(MINUS, new_ref("j"), new_constant(1)))));
        trans_exp(root, true, false);
    }

}

int ma11in()
{
    study::test();
}

