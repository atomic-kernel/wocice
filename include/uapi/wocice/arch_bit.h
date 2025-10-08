#pragma once

#if defined(__LP32__) + defined(__ILP32__) + defined(__LP64__) + defined(__LLP64__)  + defined(__ILP64__) != 1
#error "data model unkown!"
#endif

/*
 * uintregs_t: type which fit the arch general register size
 */
#if defined(__amd64__) || \
	defined(__amd64) || \
	defined(__x86_64__) || \
	defined(__x86_64) || \
	defined(_M_AMD64) || \
	defined(__aarch64__) || \
	defined(__powerpc64__) || \
	defined(__ppc64__) || \
	defined(__PPC64__) || \
	defined(_ARCH_PPC64)

#define IS_64BIT 1
#define ARCH_BIT 64

#ifndef __ASSEMBLY__
typedef __UINT64_TYPE__ uintregs_t;
typedef __INT64_TYPE__ intregs_t;
#endif

#if !defined(__LP64__) && !defined(__LLP64__) && !defined(__ILP64__) && !defined(__ILP32__)
#error "Fault"
#endif

#elif defined(__i386) || \
	defined(__i386__) || \
	defined(__i486__) || \
	defined(__i586__) || \
	defined(__i686__) || \
	defined(_M_I86) || \
	defined(__arm) || \
	defined(__powerpc) || \
	defined(__powerpc__) || \
	defined(__ppc__) || \
	defined(__PPC__) || \
	defined(_ARCH_PPC)

#define IS_32BIT 1
#define ARCH_BIT 32

#ifndef __ASSEMBLY__
typedef __UINT32_TYPE__ uintregs_t;
typedef __INT32_TYPE__ intregs_t;
#endif

#if !defined(__LP32__) && !defined(__ILP32__)
#error "Fault"
#endif

#else
#error "Unknown arch"
#endif

#ifndef __ASSEMBLY__
_Static_assert(sizeof(uintregs_t) * __CHAR_BIT__ == ARCH_BIT &&
	       _Alignof(uintregs_t) == sizeof(uintregs_t) &&
	       sizeof(intregs_t) * __CHAR_BIT__ == ARCH_BIT &&
	       _Alignof(intregs_t) == sizeof(intregs_t),
	       "Size check failed!");
#endif
