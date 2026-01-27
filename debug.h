// Debugging utilities.

#pragma once

#include "state.h"

#define pcRel(pc, p) (cast(int, (pc) - (p)->code) - 1)

#define getline(f, pc) (((f)->lineInfo) ? (f)->lineInfo[pc] : 0)

#define RESET_HOOK_COUNT(L) (L->hookCount = L->baseHookCount)

LUAI_FUNC void Error_typeError(lua_State *L, const Value *o,
                               const char *opname);
LUAI_FUNC void Error_concatError(lua_State *L, StackIndex p1, StackIndex p2);
LUAI_FUNC void Error_arithmeticError(lua_State *L, const Value *p1,
                                     const Value *p2);
[[noreturn]] LUAI_FUNC void Error_orderError(lua_State *L, const Value *p1,
                                             const Value *p2);
[[noreturn]] LUAI_FUNC void Error_runError(lua_State *L, const char *fmt, ...);
[[noreturn]] LUAI_FUNC void Error_errorMsg(lua_State *L);
LUAI_FUNC int Error_checkCode(const Prototype *pt);
LUAI_FUNC int Error_checkOpenOp(Instruction i);
LUAI_FUNC void API_pushObject(lua_State *L, const Value *o);

LUAI_DATA const char *const Debug_typeNames[];
