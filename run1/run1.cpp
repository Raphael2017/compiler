#include "run.h"
#include "translate.h"
#include "symbol.h"
#include "string"
#include "assert.h"
#include "syntax_tree.h"
#include "string.h"

enum INST_ENUM { LOC = 4017, LOA, LOV, STN, STO, JMP, CJMP, IND, ADD, SUB, MPI, DIV, GT, GTE, LTE, LT, EQ, NEQ, CALL, CALL_INNER, RET, ALC, DALC  } ;

#define C_SIZE (1 << 20)
#define S_SIZE (1 << 20)

static int MEMORY_STACK[S_SIZE] = { 0 };
static unsigned char MEMORY_CODE[C_SIZE] = { 0 };

static int FP = S_SIZE - 1;
static int SP = S_SIZE - 1;
static int IP = 0;

/*
int get_heap(unsigned int size, int** out) {
    static int i = 0;
    int ret = i;
    i += size + 1;
    *out = MEMORY_STACK + ret;
    return ret;
}*/

struct Header {
    Header *next_;
    unsigned int used_size_;
    unsigned int free_size_;
};
static unsigned int HEAP_SIZE = S_SIZE / 2;
static Header *memptr = nullptr;
static unsigned int HEADER_SIZE_INT = (sizeof(Header)/sizeof(int));

int get_heap(unsigned int size_int, int** out) {
    if (!memptr) {
        memptr = (Header*)MEMORY_STACK;
        memptr->next_ = memptr;
        memptr->used_size_ = 1;
        memptr->free_size_ = HEAP_SIZE / HEADER_SIZE_INT;
    }
    unsigned int size_unit = (size_int - 1 + HEADER_SIZE_INT) / HEADER_SIZE_INT + 1;
    Header *p = nullptr;
    for (p = memptr; (p->next_ != memptr) && (p->free_size_ < size_unit); p = p->next_);
    if (p->free_size_ < size_unit)
        assert(false);      /* heap memory not enough error */
    Header *newp = p + p->used_size_;
    newp->used_size_ = size_unit;
    newp->free_size_ = p->free_size_ - size_unit;
    newp->next_ = p->next_;
    p->free_size_ = 0;
    p->next_ = newp;
    memptr = newp;
    *out = (int*)(newp+1);
    return *out - MEMORY_STACK;
}

void free_heap(int pos) {
    Header *free = (Header*)(MEMORY_STACK + pos) - 1;
    Header *p = nullptr, *prev = nullptr;
    for (p = memptr->next_, prev = memptr; (p != memptr)&&(p != free); prev = p, p = p->next_);
    if (p != free)
        return;  /* pos is not valid */
    prev->free_size_ += p->free_size_ + p->used_size_;
    prev->next_ = p->next_;
    memptr = prev;
}



int* push_code(int inst1, int inst2) {
    static int i = 0;
    int ret = i;
    memcpy(MEMORY_CODE+i, &inst1, sizeof(inst1));
    i = i + sizeof(int);
    memcpy(MEMORY_CODE+i, &inst2, sizeof(inst2));
    i = i + sizeof(int);
    return (int*)(MEMORY_CODE + i);
}

void push_stack(int a) {
    MEMORY_STACK[--SP] = a;
}

int pop_stack() {
    return MEMORY_STACK[SP++];
}

int top_stack() {
    return MEMORY_STACK[SP];
}

int mem_stack(int i) {
    return MEMORY_STACK[i];
}

void set_stack(int pos, int i) {
    MEMORY_STACK[pos] = i;
}

void dump_code() {
    int* it = (int*)MEMORY_CODE;
    while (!(it[0] == 0 && it[1] == 0)) {
        switch (INST_ENUM(it[0])) {
            case LOC: {
                printf("%-6s%d\n", "LOC", it[1] );
            } break;
            case LOA: {
                printf("%-6s%d\n", "LOA", it[1] );
            } break;
            case LOV: {
                printf("%-6s%d\n", "LOV", it[1] );
            } break;
            case STN: {
                printf("%-6s\n", "STN" );
            } break;
            case STO: {
                printf("%-6s\n", "STO" );
            } break;
            case JMP: {
                printf("%-6s%d\n", "JMP", it[1] );
            } break;
            case CJMP: {
                printf("%-6s%d\n", "CJMP", it[1] );
            } break;
            case IND: {
                printf("%-6s%d\n", "IND", it[1] );
            } break;
            case ADD: {
                printf("%-6s\n", "ADD" );
            } break;
            case SUB: {
                printf("%-6s\n", "SUB" );
            } break;
            case MPI: {
                printf("%-6s\n", "MPI" );
            } break;
            case DIV: {
                printf("%-6s\n", "DIV" );
            } break;
            case GT: {
                printf("%-6s\n", "GT" );
            } break;
            case GTE: {
                printf("%-6s\n", "GTE" );
            } break;
            case LTE: {
                printf("%-6s\n", "LTE" );
            } break;
            case LT: {
                printf("%-6s\n", "LT" );
            } break;
            case EQ: {
                printf("%-6s\n", "EQ" );
            } break;
            case NEQ: {
                printf("%-6s\n", "NEQ" );
            } break;
            case CALL: {
                printf("%-6s%d\n", "CALL", it[1] );
            } break;
            case CALL_INNER: {
                printf("%-6s%d\n", "CALL_INNER", it[1] );
            } break;
            case RET: {
                printf("%-6s\n", "RET" );
            } break;
            case ALC: {
                printf("%-6s%d\n", "ALC", it[1] );
            } break;
            case DALC: {
                printf("%-6s%d\n", "DALC", it[1] );
            } break;
            default:{
                assert(false);
            }
        }
        it = it + 2;
    }
}



struct Patch {
    int pos_use_;
    int *p_;
};

struct PatchList {
    Patch *patch_;
    PatchList *next_;
};

struct AssEntry {
    int decl_pos_;
    bool is_decled_;
    PatchList *patches_;
};

Patch *make_patch(int pos_use, int *p) {
    Patch *ret = new Patch;
    ret->pos_use_ = pos_use;
    ret->p_ = p;
    return  ret;
}

PatchList *make_patch_list(Patch *patch, PatchList *l) {
    PatchList *ret = new PatchList;
    ret->patch_ = patch;
    ret->next_ = l;
    return ret;
}

AssEntry *make_assentry(int decl_pos, bool is_decled, PatchList *ps) {
    AssEntry *ret = new AssEntry;
    ret->decl_pos_ = decl_pos;
    ret->is_decled_ = is_decled;
    ret->patches_ = ps;
    return ret;
}

void run() {
    FP = S_SIZE - 1; SP = FP; IP = 0;
    int* it = (int*)(MEMORY_CODE+ sizeof(int)*2*IP);
    while (!(it[0] == 0 && it[1] == 0)) {
        switch (INST_ENUM(it[0])) {
            case LOC: {
                push_stack(it[1]);
            } break;
            case LOA: {
                push_stack(FP+it[1]);
            } break;
            case LOV: {
                push_stack(mem_stack(FP+it[1]));
            } break;
            case STN: {
                int pos = pop_stack();
                set_stack(pos, top_stack());
            } break;
            case STO: {
                int pos = pop_stack();
                int v = pop_stack();
                set_stack(pos, v);
            } break;
            case JMP: {
                IP += it[1];
            } break;
            case CJMP: {
                int a = pop_stack();
                if (a==0)
                    IP += it[1];
            } break;
            case IND: {
                int base = pop_stack();
                push_stack(mem_stack(base + it[1]));
            } break;
            case ADD: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l+r);
            } break;
            case SUB: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l-r);
            } break;
            case MPI: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l*r);
            } break;
            case DIV: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l/r);
            } break;
            case GT: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l>r ? 1:0);
            } break;
            case GTE: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l>=r ? 1:0);
            } break;
            case LTE: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l<=r ? 1:0);
            } break;
            case LT: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l<r ? 1:0);
            } break;
            case EQ: {
                int r = pop_stack();
                int l = pop_stack();
                int m = l==r ? 1:0;
                push_stack(l==r ? 1:0);
            } break;
            case NEQ: {
                int r = pop_stack();
                int l = pop_stack();
                push_stack(l!=r ? 1:0);
            } break;
            case CALL: {
                push_stack(IP+1);
                push_stack(FP);
                push_stack(0);  // reserved1
                FP = SP;
                IP += it[1];
            } break;
            case CALL_INNER: {
                switch (it[1]) {
                    case 0: {   // ctor
                        /*todo*/
                        int cnt = pop_stack();
                        int *out = nullptr;
                        int ret = get_heap(1+cnt, &out);
                        out[0] = cnt;
                        for (int i = 0; i < cnt; ++i) {
                            out[1+i] = pop_stack();
                        }
                        pop_stack();
                        push_stack(ret+1);
                    } break;
                    case -1: {  // print_int
                        pop_stack();
                        int n = pop_stack();
                        printf("%d\n", n);
                    } break;
                    case -2: {  // print_str
                        pop_stack();
                        int pos = pop_stack();
                        int length = mem_stack(pos);
                        char *s = (char*)(MEMORY_STACK+pos+1);
                        std::string str(s, s+length);
                        printf("%s\n", str.c_str());
                    } break;
                    case -3: {  // array_cnt
                        pop_stack();
                        int pos = pop_stack();
                        int ant = mem_stack(pos - 1);
                        pop_stack();
                        push_stack(ant);
                    } break;
                    default:
                        assert(false);
                }
            } break;
            case RET: {
                if (SP == S_SIZE - 1)
                    return;
                pop_stack();    // reserved1
                int old_fp = pop_stack();
                int old_ip = pop_stack();
                int cnt = pop_stack();
                int top = top_stack();
                for (int i = 0; i < cnt; ++i) {
                    pop_stack();
                }
                FP = old_fp;
                IP = old_ip-1;
            } break;
            case ALC: {
                for (int i = 0; i < it[1]; ++i) {
                    push_stack(0);
                }
            } break;
            case DALC: {
                for (int i = 0; i < it[1]; ++i) {
                    pop_stack();
                }
            } break;
            default:{
                assert(false);
            }
        }
        IP++;it = (int*)(MEMORY_CODE+ sizeof(int)*2*IP);
    }
}

bool load_insts(InstList *src) {
    S_table lab_env = S_empty();
    S_enter(lab_env,make_symbol("<CTOR>"), make_assentry(-1, true, nullptr));
    S_enter(lab_env,make_symbol("PRINT_INT"), make_assentry(-2, true, nullptr));
    S_enter(lab_env,make_symbol("PRINT_STR"), make_assentry(-3, true, nullptr));
    S_enter(lab_env,make_symbol("ARRAY_CNT"), make_assentry(-4, true, nullptr));
    int line = 0;
    int *t = (int*)(MEMORY_CODE+0);
    for (InstList *it = src; it; it = it->next_) {
        char *inst_str = it->inst_;
        int i = 0, j = 0;
        for (i = 0; inst_str[i] == ' '; ++i);   // skip white
        j = i;
        for (; inst_str[i] != ' '; ++i);   // inst enum
        std::string inst(inst_str+j, inst_str+i);
        for (; inst_str[i] == ' '; ++i);   // skip white
        j = i;
        for (; inst_str[i] != ' ' && inst_str[i] != '\0'; ++i);   // inst enum
        std::string inst1(inst_str+j, inst_str+i);
        /*enum INST_ENUM { LOC = 4017, LOA, LOV, STN, STO, JMP, CJMP, IND, ADD, SUB, MPI, DIV, GT, GTE, LTE, LT, EQ, NEQ, CALL, RET, ALC, DALC  } ;*/
        if (inst == "LOC") {
            t = push_code(LOC, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "LOA") {
            t = push_code(LOA, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "LOV") {
            t = push_code(LOV, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "STN") {
            t = push_code(STN, 0); ++line;
        }
        else if (inst == "STO") {
            t = push_code(STO, 0); ++line;
        }
        else if (inst == "JMP") {
            Symbol *sym = make_symbol(inst1.c_str());
            AssEntry *entry = (AssEntry*)S_look(lab_env, sym);
            if (!entry || entry->is_decled_ == false) {
                S_enter(lab_env, sym, make_assentry(-1, false, make_patch_list(make_patch(line, t+1), entry ? entry->patches_ : nullptr)));
                t = push_code(JMP, 0); ++line;
            }
            else {
                t = push_code(JMP, entry->decl_pos_-(line+1)); ++line;
            }
        }
        else if (inst == "CJMP") {
            Symbol *sym = make_symbol(inst1.c_str());
            AssEntry *entry = (AssEntry*)S_look(lab_env, sym);
            if (!entry || entry->is_decled_ == false) {
                S_enter(lab_env, sym, make_assentry(-1, false, make_patch_list(make_patch(line, t+1), entry ? entry->patches_ : nullptr)));
                t = push_code(CJMP, 0); ++line;
            }
            else {
                t = push_code(CJMP, entry->decl_pos_-(line+1)); ++line;
            }
        }
        else if (inst == "CALL") {
            Symbol *sym = make_symbol(inst1.c_str());
            AssEntry *entry = (AssEntry*)S_look(lab_env, sym);
            if (!entry || entry->is_decled_ == false) {
                S_enter(lab_env, sym, make_assentry(0, false, make_patch_list(make_patch(line, t+1), entry ? entry->patches_ : nullptr)));
                t = push_code(CALL, 0); ++line;
            }
            else {
                if (entry->decl_pos_ < 0) {
                    t = push_code(CALL_INNER, 1+entry->decl_pos_); ++line;
                }
                else {
                    t = push_code(CALL, entry->decl_pos_-(line+1)); ++line;
                }

            }
        }
        else if (inst == "IND") {
            t = push_code(IND, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "ADD") {
            t = push_code(ADD, 0); ++line;
        }
        else if (inst == "SUB") {
            t = push_code(SUB, 0); ++line;
        }
        else if (inst == "MPI") {
            t = push_code(MPI, 0); ++line;
        }
        else if (inst == "DIV") {
            t = push_code(DIV, 0); ++line;
        }
        else if (inst == "GT")  {
            t = push_code(GT, 0); ++line;
        }
        else if (inst == "GE") {
            t = push_code(GTE, 0); ++line;
        }
        else if (inst == "LE") {
            t = push_code(LTE, 0); ++line;
        }
        else if (inst == "LT") {
            t = push_code(LT, 0); ++line;
        }
        else if (inst == "EQ") {
            t = push_code(EQ, 0); ++line;
        }
        else if (inst == "NEQ") {
            t = push_code(NEQ, 0); ++line;
        }
        else if (inst == "RET") {
            t = push_code(RET, 0); ++line;
        }
        else if (inst == "ALC") {
            t = push_code(ALC, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "DALC") {
            t = push_code(DALC, atoi(inst1.c_str())); ++line;
        }
        else if (inst == "LAB" || inst == "FLAB") {
            Symbol *sym = make_symbol(inst1.c_str());
            AssEntry *entry = (AssEntry*)S_look(lab_env, sym);
            if (!entry) {
                S_enter(lab_env, sym, make_assentry(line, true, nullptr));
            }
            else {
                assert(entry->is_decled_ == false);
                entry->is_decled_ = true;
                entry->decl_pos_ = line;
                for (PatchList *it = entry->patches_; it; it = it->next_) {
                    *(it->patch_->p_) = entry->decl_pos_ - (it->patch_->pos_use_+1);
                }
            }
        }
        else if (inst == "<load_string>") {
            int m = inst1.length() / sizeof(int);
            if (m * sizeof(int) < inst1.length())
                m++;
            int cnt = 1 + m;
            int *p = nullptr;
            int pos = get_heap(cnt, &p);
            *p = inst1.length();
            p++;
            memcpy(p, inst1.c_str(), inst1.length());
            t = push_code(LOC, pos); ++line;
        }
        else { assert(false);   /* unreachable */ }
    }
    //dump_code();
    printf("//////////////////////////////////////////////////\n\n");
    run();
}