#ifndef ENTRY_H
#define ENTRY_H

struct TypeInfo;
struct Access;
struct Symbol;
struct Frame;
struct TranslateLevel;

struct Entry {
    enum { FUNC, VAR} kind_;
    union {
        struct {
            TypeInfo *type_;
            Access *access_;
            TranslateLevel *level_;
        } var_;
        struct {
            TypeInfo *type_;
            Symbol *label_;
            Frame *frame_;
        } func_;
    } u;
};


Entry* make_var_entry(TypeInfo *type, Access *access, TranslateLevel *level);
Entry* make_func_entry(TypeInfo *type, Symbol *label);

#endif