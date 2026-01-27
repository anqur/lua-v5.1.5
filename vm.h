// Virtual machine.

#pragma once

#include "object.h"
#include "stack.h"
#include "tag.h"

LUAI_FUNC bool Object_lessThan(lua_State *L, const Value *l, const Value *r);
LUAI_FUNC bool Object_equal(lua_State *L, const Value *t1, const Value *t2);
LUAI_FUNC const Value *VM_toNumber(const Value *obj, Value *n);
LUAI_FUNC bool VM_toString(lua_State *L, StackIndex obj);
LUAI_FUNC void VM_getTable(lua_State *L, const Value *t, Value *key,
                           StackIndex val);
LUAI_FUNC void VM_setTable(lua_State *L, const Value *t, Value *key,
                           StackIndex val);
LUAI_FUNC void VM_execute(lua_State *L, int nexeccalls);
LUAI_FUNC void VM_concat(lua_State *L, int total, int last);

#define tostring(L, o) ((GET_TYPE(o) == LUA_TYPE_STRING) || (VM_toString(L, o)))

#define tonumber(o, n)                                                         \
  (GET_TYPE(o) == LUA_TYPE_NUMBER || (((o) = VM_toNumber(o, n)) != nullptr))

#define equalobj(L, o1, o2)                                                    \
  (GET_TYPE(o1) == GET_TYPE(o2) && Object_equal(L, o1, o2))
