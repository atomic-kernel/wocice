#pragma once

#include <uapi/wocice/arch_bit.h>

#ifdef IS_64BIT
# define CONFIG_64BIT 1
# ifndef __LP64__
#  error "Not support data model"
# endif
#elif !defined(__ILP32__) // 32BIT
# error "Not support data model"
#endif

#if defined(__amd64__) || \
        defined(__amd64) || \
        defined(__x86_64__) || \
        defined(__x86_64) || \
	defined(_M_AMD64)
#define CONFIG_X86_64 1
#define CONFIG_X86 1
#elif defined(__i386) || \
	defined(__i386__) || \
	defined(__i486__) || \
	defined(__i586__) || \
	defined(__i686__) || \
	defined(_M_I86)
#define CONFIG_X86 1
#elif defined(__aarch64__)
#define CONFIG_ARM64 1
#endif

#ifndef CONFIG_X86_64
#error "Unsupport"
#endif
