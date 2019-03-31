#ifndef TRANSLATE_H
#define TRANSLATE_H


struct SyntaxMoonStmt;
struct SyntaxExp;
struct Frame;
struct TAB_table_;
struct SyntaxMoonStmtsList;

struct TranslateExp;

struct TranslateLevel {
    TranslateLevel *parent_;
};

struct InstList {
    char *inst_;
    InstList *next_;
};

TranslateLevel* make_new_level(TranslateLevel *parent);

void translate(SyntaxMoonStmtsList *stmts);


#endif