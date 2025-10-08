#pragma once

#undef BOOL_MAX
#define BOOL_MAX 1
#undef BOOL_WIDTH
#ifdef __BOOL_WIDTH__
#define BOOL_WIDTH __BOOL_WIDTH__
#else
#define BOOL_WIDTH   1
#endif

#undef CHAR_BIT
#undef CHAR_WIDTH
#undef SCHAR_WIDTH
#undef UCHAR_WIDTH
#define CHAR_BIT __CHAR_BIT__
#define CHAR_WIDTH __CHAR_BIT__
#ifdef __SCHAR_WIDTH__
#define SCHAR_WIDTH __SCHAR_WIDTH__
#define UCHAR_WIDTH __SCHAR_WIDTH__
#else
#define SCHAR_WIDTH __CHAR_BIT__
#define UCHAR_WIDTH __CHAR_BIT__
#endif

#undef SCHAR_MIN
#undef SCHAR_MAX
#undef UCHAR_MAX
#define SCHAR_MIN (-SCHAR_MAX - 1)
#define SCHAR_MAX __SCHAR_MAX__
#if __SCHAR_MAX__ == __INT_MAX__
# define UCHAR_MAX (SCHAR_MAX * 2U + 1U)
#else
# define UCHAR_MAX (SCHAR_MAX * 2 + 1)
#endif

#undef CHAR_MIN
#undef CHAR_MAX
#ifdef __CHAR_UNSIGNED__  /* -funsigned-char */
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#else
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX __SCHAR_MAX__
#endif

#undef SHRT_WIDTH
#undef USHRT_WIDTH
#define SHRT_WIDTH __SHRT_WIDTH__
#define USHRT_WIDTH __SHRT_WIDTH__

#undef SHRT_MIN
#undef SHRT_MAX
#undef USHRT_MAX
#define SHRT_MIN (-SHRT_MAX - 1)
#define SHRT_MAX __SHRT_MAX__
#if __SHRT_MAX__ == __INT_MAX__
# define USHRT_MAX (SHRT_MAX * 2U + 1U)
#else
# define USHRT_MAX (SHRT_MAX * 2 + 1)
#endif

#undef INT_WIDTH
#undef UINT_WIDTH
#define INT_WIDTH __INT_WIDTH__
#define UINT_WIDTH __INT_WIDTH__

#undef INT_MAX
#undef INT_MIN
#undef UINT_MAX
#define INT_MAX __INT_MAX__
#define INT_MIN (-INT_MAX - 1)
#define UINT_MAX  (__INT_MAX__  * 2U + 1U)

#undef LONG_WIDTH
#undef ULONG_WIDTH
#define LONG_WIDTH __LONG_WIDTH__
#define ULONG_WIDTH __LONG_WIDTH__

#undef LONG_MAX
#undef LONG_MIN
#undef ULONG_MAX
#define LONG_MAX __LONG_MAX__
#define LONG_MIN (-__LONG_MAX__ - 1L)
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)

#undef LLONG_WIDTH
#undef ULLONG_WIDTH
#ifdef __LLONG_WIDTH__
#define LLONG_WIDTH __LLONG_WIDTH__
#define ULLONG_WIDTH __LLONG_WIDTH__
#elif defined(__LONG_LONG_WIDTH__)
#define LLONG_WIDTH __LONG_LONG_WIDTH__
#define ULLONG_WIDTH __LONG_LONG_WIDTH__
#else
#error "builtin LLONG_WIDTH is not define"
#endif

#undef LLONG_MAX
#undef LLONG_MIN
#undef ULLONG_MAX
#undef LONG_LONG_MIN
#undef LONG_LONG_MAX
#undef ULONG_LONG_MAX
#define LLONG_MAX __LONG_LONG_MAX__
#define LLONG_MIN (-__LONG_LONG_MAX__ - 1LL)
#define ULLONG_MAX (__LONG_LONG_MAX__ * 2ULL + 1ULL)
#define LONG_LONG_MIN LLONG_MIN
#define LONG_LONG_MAX LLONG_MAX
#define ULONG_LONG_MAX ULLONG_MAX
