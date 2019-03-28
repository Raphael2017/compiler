#include "entry.h"
#include "frame.h"
#include "assert.h"
#include "type_info.h"

Entry* make_var_entry(TypeInfo *type, Access *access, TranslateLevel *level) {
    Entry *ret = new Entry;
    ret->kind_ = Entry::VAR;
    ret->u.var_.type_ = type;
    ret->u.var_.access_ = access;
    ret->u.var_.level_ = level;
    return ret;
}

Entry* make_func_entry(TypeInfo *type, Symbol *label) {
    assert(type->kind_ == TypeInfo::FUNC);
    Frame *frame = make_frame(type);
    Entry *ret = new Entry;
    ret->kind_ = Entry::FUNC;
    ret->u.func_.type_ = type;
    ret->u.func_.label_ = label;
    ret->u.func_.frame_ = frame;
    return ret;
}


