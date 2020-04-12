#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstddef>

inline static const HMODULE HB_MODULE_HANDLE = GetModuleHandle(nullptr);

#ifdef HB_BASE_ADDRESS
#define HB_ASLR(address) (reinterpret_cast<std::size_t>(HB_MODULE_HANDLE) + \
    static_cast<std::size_t>(address) - static_cast<std::size_t>(HB_BASE_ADDRESS))
#else
#define HB_ASLR(address) (reinterpret_cast<std::size_t>(HB_MODULE_HANDLE) + \
    static_cast<std::size_t>(address))
#endif

#define HB_FUNC_PTR(address, callingConvention, returnType, name, ...)\
    typedef returnType (callingConvention*name##_ptr_t)(__VA_ARGS__);\
    inline static const name##_ptr_t name = reinterpret_cast<name##_ptr_t>(address);\
    inline static name##_ptr_t name##_original = reinterpret_cast<name##_ptr_t>(address)

#define HB_MEMBER_FUNC(address, className, returnType, name, ...)\
    typedef returnType (__thiscall*name##_ptr_t)(className* thisPtr, __VA_ARGS__);\
    inline static const name##_ptr_t name##_ptr = (name##_ptr_t)(address);\
    inline static name##_ptr_t name##_original = reinterpret_cast<name##_ptr_t>(address)

#define HB_CALL_ORIGINAL(name, ...) name##_original(__VA_ARGS__)
#define HB_HOOK(callingConvention, returnType, name, ...)\
    returnType callingConvention name##_hook(__VA_ARGS__)

#if defined(x64) || defined(_AMD64_)
#define HB_HOOK_MEMBER(className, returnType, name, ...)\
    returnType __fastcall className##_##name##_hook(className* thisPtr,\
        __VA_ARGS__)
#else
#define HB_HOOK_MEMBER(className, returnType, name, ...)\
    returnType __fastcall className##_##name##_hook(className* thisPtr,\
        void* DUMMY_ARGUMENT, __VA_ARGS__)
#endif
