#pragma once

#ifndef __ASSEMBLY__
#ifndef __cplusplus /* C */
#define NULL ((void *)0)
#elif defined(__GNUG__) /* GNU C++ */
#define NULL __null
#else /* STD C++ */
#define NULL 0
#endif

typedef __SIZE_TYPE__ size_t;
#ifdef __ILP32__
__extension__ typedef int ssize_t;
#else
typedef long int ssize_t;
#endif

#define offsetof(TYPE, MEMBER)	__builtin_offsetof(TYPE, MEMBER)

#endif /*  __ASSEMBLY__ */
