#ifndef FRAME_H
#define FRAME_H

#define STACK_BOTTOM    (1 << 20)

struct Frame;
struct TypeInfo;

struct Access {
    int offset_;
    Frame *frame_;
};

struct AccessList {
    Access *access_;
    AccessList *next_;
};

/* global frame's FP is fixed and  Runtime Unique  */
struct Frame {
    bool is_global_;
    AccessList *access_list_;
    Access *result_;
    TypeInfo *type_;
    int cur_local_count_;
    int max_local_count_;
};

Access* make_access(int offset, Frame *frame);

AccessList* make_access_list(Access *access, AccessList *next);

Frame* make_frame(TypeInfo *type);

Frame* make_global_frame();

Access* alloc_local(Frame *frame);

void dealloc_local(Access* access);

#endif