#include "frame.h"
#include "type_info.h"
#include "assert.h"

Access* make_access(int offset, Frame *frame, bool is_ref) {
    Access *ret = new Access;
    ret->offset_ = offset;
    ret->frame_ = frame;
    ret->is_ref_ = is_ref;
    return ret;
}

AccessList* make_access_list(Access *access, AccessList *next) {
    AccessList *ret = new AccessList;
    ret->access_ = access;
    ret->next_ = next;
    return ret;
}

Frame* make_frame(TypeInfo *type) {
    assert(type->kind_ == TypeInfo::FUNC);

    //  _ _ return_value p2 p1  NEXT(this_inst) FP reserverd1 |
    Frame *ret = new Frame;

    AccessList* access_list = nullptr;
    AccessList* access_list_head = nullptr;
    int i = 0;
    for (TypeInfoList *it = type->u.func_proto.params_; it; ++i, it = it->next_) {
        if (0 == i) {
            access_list = make_access_list(make_access(4+i, ret, is_ref(it->type_info_)), nullptr);
            access_list_head = access_list;
        }
        else
        {
            access_list->next_ = make_access_list(make_access(4+i, ret, is_ref(it->type_info_)), nullptr);
            access_list = access_list->next_;
        }
    }
    ret->access_list_ = access_list_head;
    ret->result_ = make_access(4+i, ret, is_ref(type->u.func_proto.result_));
    ret->cur_local_count_ = 0;
    ret->max_local_count_ = 0;
    ret->is_global_ = false;
    ret->type_ = type;
    return ret;
}

Frame* make_global_frame() {
    Frame *ret = new Frame;
    ret->access_list_ = nullptr;
    ret->cur_local_count_ = 0;
    ret->max_local_count_ = 0;
    ret->is_global_ = true;
    return ret;
}

Access* alloc_local(Frame *frame, TypeInfo *type) {
    frame->cur_local_count_++;
    if (frame->max_local_count_ < frame->cur_local_count_)
        frame->max_local_count_ = frame->cur_local_count_;
    Access *ret = make_access(-frame->cur_local_count_, frame, is_ref(type));
    return ret;
}

void dealloc_local(Access* access) {
    access->frame_->cur_local_count_--;
}