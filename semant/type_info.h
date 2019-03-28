#ifndef TYPE_INFO_H
#define TYPE_INFO_H

struct TypeInfoList;

struct TypeFieldTypeInfoList;

struct TypeFieldTypeInfo;

struct Symbol;

struct TypeInfo {
    enum { VOID, INT, STRING, ARRAY, STRUCT, NAMED, FUNC } kind_;
    union {
        TypeInfo *array_elem_;
        TypeFieldTypeInfoList *struct_fields_type_;
        struct {
            Symbol *sym_;
            TypeInfo *type_info_;
        } named_;  // typedef , type header
        struct {
            bool is_variable_params_;
            TypeInfo *result_;
            Symbol *func_;
            TypeInfoList *params_;
        } func_proto;
    } u;
};

struct TypeInfoList {
    TypeInfo *type_info_;
    TypeInfoList *next_;
};

struct TypeFieldTypeInfoList {
    TypeFieldTypeInfo *field_type_info_;
    TypeFieldTypeInfoList *next_;
};

struct TypeFieldTypeInfo {
    Symbol *field_;
    TypeInfo *field_type_;
};

TypeInfo* make_void_type_info();

TypeInfo* make_int_type_info();

TypeInfo* make_string_type_info();

TypeInfo* make_array_type_info(TypeInfo *array_elem);

TypeInfo* make_struct_type_info(TypeFieldTypeInfoList *struct_fields);

TypeInfo* make_named_type_info(Symbol *sym, TypeInfo *type_info);

TypeInfo* make_func_type_info(TypeInfo *result, Symbol *func, TypeInfoList *params);

TypeInfo* make_func_type_info_with_variable_params(Symbol *func);

TypeInfoList* make_type_info_list(TypeInfo *type_info, TypeInfoList *next);

TypeFieldTypeInfoList* make_field_type_info_list(TypeFieldTypeInfo *h, TypeFieldTypeInfoList *next);

TypeFieldTypeInfo* make_field_type_info(Symbol *field, TypeInfo *type);

#endif