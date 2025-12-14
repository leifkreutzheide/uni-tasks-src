
#include <float.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main() {
    printf("Testing various data types in C:\n\n");

    // Test for bool (stdbool.h)
    printf("bool: %zu Byte\n", sizeof(bool));
    printf("  true: %d\n", true);
    printf("  false: %d\n\n", false);

    // Test for char (stdio.h, limits.h)
    printf("char: %zu Byte\n", sizeof(char));
    printf("  CHAR_MIN: %d\n", CHAR_MIN);
    printf("  CHAR_MAX: %d\n", CHAR_MAX);
    printf("  UCHAR_MAX: %u\n", UCHAR_MAX);
    printf("  SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("  SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("  UCHAR_MAX: %u\n\n", UCHAR_MAX);

    // Test for short (stdio.h, limits.h)
    printf("short: %zu Byte\n", sizeof(short));
    printf("  SHRT_MIN: %d\n", SHRT_MIN);
    printf("  SHRT_MAX: %d\n", SHRT_MAX);
    printf("  USHRT_MAX: %u\n\n", USHRT_MAX);

    // Test for int (stdio.h, limits.h)
    printf("int: %zu Byte\n", sizeof(int));
    printf("  INT_MIN: %d\n", INT_MIN);
    printf("  INT_MAX: %d\n", INT_MAX);
    printf("  UINT_MAX: %u\n\n", UINT_MAX);

    // Test for long (stdio.h, limits.h)
    printf("long: %zu Byte\n", sizeof(long));
    printf("  LONG_MIN: %ld\n", LONG_MIN);
    printf("  LONG_MAX: %ld\n", LONG_MAX);
    printf("  ULONG_MAX: %lu\n\n", ULONG_MAX);

    // Test for long long (stdio.h, limits.h)
    printf("long long: %zu Byte\n", sizeof(long long));
    printf("  LLONG_MIN: %lld\n", LLONG_MIN);
    printf("  LLONG_MAX: %lld\n", LLONG_MAX);
    printf("  ULLONG_MAX: %llu\n\n", ULLONG_MAX);

    // Test for float (float.h)
    printf("float: %zu Byte\n", sizeof(float));
    printf("  FLT_MIN: %e\n", FLT_MIN);
    printf("  FLT_MAX: %e\n", FLT_MAX);
    printf("  FLT_DIG: %d\n", FLT_DIG);
    printf("  FLT_EPSILON: %e\n", FLT_EPSILON);
    printf("  FLT_MIN_EXP: %d\n", FLT_MIN_EXP);
    printf("  FLT_MAX_EXP: %d\n\n", FLT_MAX_EXP);

    // Test for double (float.h)
    printf("double: %zu Byte\n", sizeof(double));
    printf("  DBL_MIN: %e\n", DBL_MIN);
    printf("  DBL_MAX: %e\n", DBL_MAX);
    printf("  DBL_DIG: %d\n", DBL_DIG);
    printf("  DBL_EPSILON: %e\n", DBL_EPSILON);
    printf("  DBL_MIN_EXP: %d\n", DBL_MIN_EXP);
    printf("  DBL_MAX_EXP: %d\n\n", DBL_MAX_EXP);

    // Test for long double (float.h)
    printf("long double: %zu Byte\n", sizeof(long double));
    printf("  LDBL_MIN: %Le\n", LDBL_MIN);
    printf("  LDBL_MAX: %Le\n", LDBL_MAX);
    printf("  LDBL_DIG: %d\n", LDBL_DIG);
    printf("  LDBL_EPSILON: %Le\n", LDBL_EPSILON);
    printf("  LDBL_MIN_EXP: %d\n", LDBL_MIN_EXP);
    printf("  LDBL_MAX_EXP: %d\n\n", LDBL_MAX_EXP);

    // Test for int8_t, uint8_t (stdint.h)
    printf("int8_t: %zu Byte\n", sizeof(int8_t));
    printf("  INT8_MIN: %d\n", INT8_MIN);
    printf("  INT8_MAX: %d\n", INT8_MAX);
    printf("  UINT8_MAX: %u\n\n", UINT8_MAX);

    // Test for int16_t, uint16_t (stdint.h)
    printf("int16_t: %zu Byte\n", sizeof(int16_t));
    printf("  INT16_MIN: %d\n", INT16_MIN);
    printf("  INT16_MAX: %d\n", INT16_MAX);
    printf("  UINT16_MAX: %u\n\n", UINT16_MAX);

    // Test for int32_t, uint32_t (stdint.h)
    printf("int32_t: %zu Byte\n", sizeof(int32_t));
    printf("  INT32_MIN: %d\n", INT32_MIN);
    printf("  INT32_MAX: %d\n", INT32_MAX);
    printf("  UINT32_MAX: %u\n\n", UINT32_MAX);

    // Test for int64_t, uint64_t (stdint.h)
    printf("int64_t: %zu Byte\n", sizeof(int64_t));
    printf("  INT64_MIN: %lld\n", INT64_MIN);
    printf("  INT64_MAX: %lld\n", INT64_MAX);
    printf("  UINT64_MAX: %llu\n\n", UINT64_MAX);

    // Test for size_t (stdlib.h)
    printf("size_t: %zu Byte\n", sizeof(size_t));
    printf("  SIZE_MAX: %zu\n\n", SIZE_MAX);

    // Test for ptrdiff_t (stdlib.h)
    printf("ptrdiff_t: %zu Byte\n", sizeof(ptrdiff_t));
    printf("  PTRDIFF_MIN: %td\n", PTRDIFF_MIN);
    printf("  PTRDIFF_MAX: %td\n\n", PTRDIFF_MAX);

    return 0;
}

