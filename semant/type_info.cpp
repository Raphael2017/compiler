#include "type_info.h"

TypeInfo* make_void_type_info() {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::VOID;
    return ret;
}

TypeInfo* make_int_type_info() {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::INT;
    return ret;
}

TypeInfo* make_string_type_info() {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::STRING;
    return ret;
}

TypeInfo* make_array_type_info(TypeInfo *array_elem) {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::ARRAY;
    ret->u.array_elem_ = array_elem;
    return ret;
}

TypeInfo* make_struct_type_info(TypeFieldTypeInfoList *struct_fields) {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::STRUCT;
    ret->u.struct_fields_type_ = struct_fields;
    return ret;
}

TypeInfo* make_named_type_info(Symbol *sym, TypeInfo *type_info) {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::NAMED;
    ret->u.named_.sym_ = sym;
    ret->u.named_.type_info_ = type_info;
    return ret;
}

TypeInfo* make_func_type_info(TypeInfo *result, Symbol *func, TypeInfoList *params) {
    TypeInfo *ret = new TypeInfo;
    ret->kind_ = TypeInfo::FUNC;
    ret->u.func_proto.result_ = result;
    ret->u.func_proto.func_ = func;
    ret->u.func_proto.params_ = params;
    return ret;
}

TypeInfoList* make_type_info_list(TypeInfo *type_info, TypeInfoList *next) {
    TypeInfoList *ret = new TypeInfoList;
    ret->type_info_ = type_info;
    ret->next_ = next;
    return ret;
}

TypeFieldTypeInfoList* make_field_type_info_list(TypeFieldTypeInfo *h, TypeFieldTypeInfoList *next) {
    TypeFieldTypeInfoList *ret = new TypeFieldTypeInfoList;
    ret->field_type_info_ = h;
    ret->next_ = next;
    return ret;
}

TypeFieldTypeInfo* make_field_type_info(Symbol *field, TypeInfo *type) {
    TypeFieldTypeInfo *ret = new TypeFieldTypeInfo;
    ret->field_ = field;
    ret->field_type_ = type;
    return ret;
}