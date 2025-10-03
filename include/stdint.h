#pragma once

#ifndef __ASSEMBLY__
typedef __UINT8_TYPE__ uint8_t, u_int8_t;
typedef __INT8_TYPE__ int8_t;

typedef __UINT16_TYPE__ uint16_t, u_int16_t;
typedef __INT16_TYPE__ int16_t;

typedef __UINT32_TYPE__ uint32_t, u_int32_t;
typedef __INT32_TYPE__ int32_t;

typedef __UINT64_TYPE__ uint64_t, u_int64_t;
typedef __INT64_TYPE__ int64_t;

_Static_assert(sizeof(uint8_t) == 1 && _Alignof(uint8_t) == 1 &&
	       sizeof(int8_t) == 1 && _Alignof(int8_t) == 1 &&
	       sizeof(uint16_t) == 2 && _Alignof(uint16_t) == 2 &&
	       sizeof(int16_t) == 2 && _Alignof(int16_t) == 2 &&
	       sizeof(uint32_t) == 4 && _Alignof(uint32_t) == 4 &&
	       sizeof(int32_t) == 4 && _Alignof(int32_t) == 4 &&
	       sizeof(uint64_t) == 8 && _Alignof(uint64_t) == 8 &&
	       sizeof(int64_t) == 8 && _Alignof(int64_t) == 8,
	       "size check failed");

typedef __INTPTR_TYPE__ intptr_t;
typedef __UINTPTR_TYPE__ uintptr_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

_Static_assert(sizeof(void *) == sizeof(intptr_t) && _Alignof(void *) == _Alignof(intptr_t) &&
	       sizeof(void *) == sizeof(uintptr_t) && _Alignof(void *) == _Alignof(uintptr_t) &&
	       sizeof(void *) == sizeof(ptrdiff_t) && _Alignof(void *) == _Alignof(ptrdiff_t),
	       "size check failed");

#endif /* __ASSEMBLY__ */
