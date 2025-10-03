#pragma once

#ifndef __ASSEMBLY__
#ifndef __cplusplus

#if defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L
/* bool, true and false are keywords.  */
#else
#define bool	_Bool
#define true	1
#define false	0
#endif

#else /* __cplusplus */

/* Supporting _Bool in C++ is a GCC extension.  */
#define _Bool	bool

#if __cplusplus < 201103L
/* For C++98, define bool, false, true as a GNU extension. */
#define bool bool
#define false false
#define true true
#endif

#endif /* __cplusplus */
#endif /*  __ASSEMBLY__ */
