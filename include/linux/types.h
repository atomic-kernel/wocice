/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <uapi/linux/types.h>

#ifndef __ASSEMBLY__

#ifdef __SIZEOF_INT128__
typedef __s128 s128;
typedef __u128 u128;
#endif

typedef u32 __kernel_dev_t;
typedef __kernel_dev_t		dev_t;
typedef u32			nlink_t;

/* bsd */
typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;
typedef unsigned long		u_long;

/* sysv */
typedef unsigned char		unchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;
typedef unsigned long long	ullong;

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

#endif /*  __ASSEMBLY__ */
#endif /* _LINUX_TYPES_H */
