#include <stdio.h>
#include <stdlib.h>

extern int assemblyProcedure(int) __attribute__((weak));
extern int anotherProcedure(int, int) __attribute__((weak));
extern int maxOfThree(int, int, int) __attribute__((weak));
extern int sum1toN(int) __attribute__((weak));

static int checkResult(const char *functionName,
                       int expected,
                       int actual,
                       const char *details) {
    if (expected == actual) {
        return 1;
    }

    printf("ERROR: %s failed. %s\n", functionName, details);
    printf("  Expected: %d\n", expected);
    printf("  Actual:   %d\n", actual);
    return 0;
}

static int testAssemblyProcedure(void) {
    int success = 1;

    if (!assemblyProcedure) {
        printf("ERROR: Missing function assemblyProcedure.\n");
        printf("  Ensure Assembly.asm exports 'global assemblyProcedure' and defines the procedure.\n");
        return 0;
    }

    struct {
        int input;
        int expected;
    } tests[] = {
        {10, 30},
        {100, 120},
        {0, 20},
        {-5, 15},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int actual = assemblyProcedure(tests[i].input);
        char details[128];
        snprintf(details, sizeof(details), "Called assemblyProcedure(%d)", tests[i].input);
        success &= checkResult("assemblyProcedure", tests[i].expected, actual, details);
    }

    return success;
}

static int testAnotherProcedure(void) {
    int success = 1;

    if (!anotherProcedure) {
        printf("ERROR: Missing function anotherProcedure.\n");
        printf("  Ensure Assembly.asm exports 'global anotherProcedure' and defines the procedure.\n");
        return 0;
    }

    struct {
        int a;
        int b;
        int expected;
    } tests[] = {
        {10, 20, 30},
        {50, 100, 150},
        {-5, 5, 0},
        {123, -23, 100},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int actual = anotherProcedure(tests[i].a, tests[i].b);
        char details[128];
        snprintf(details, sizeof(details), "Called anotherProcedure(%d, %d)", tests[i].a, tests[i].b);
        success &= checkResult("anotherProcedure", tests[i].expected, actual, details);
    }

    return success;
}

static int testMaxOfThree(void) {
    int success = 1;

    if (!maxOfThree) {
        printf("ERROR: Missing function maxOfThree.\n");
        printf("  Ensure Assembly.asm exports 'global maxOfThree' and defines the procedure.\n");
        return 0;
    }

    struct {
        int a;
        int b;
        int c;
        int expected;
    } tests[] = {
        {1, 2, 3, 3},
        {3, 2, 1, 3},
        {2, 3, 1, 3},
        {5, 5, 5, 5},
        {-1, -2, -3, -1},
        {10, 10, 5, 10},
        {4, 7, 7, 7},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int actual = maxOfThree(tests[i].a, tests[i].b, tests[i].c);
        char details[128];
        snprintf(details, sizeof(details), "Called maxOfThree(%d, %d, %d)", tests[i].a, tests[i].b, tests[i].c);
        success &= checkResult("maxOfThree", tests[i].expected, actual, details);
    }

    return success;
}

static int testSum1toN(void) {
    int success = 1;

    if (!sum1toN) {
        printf("ERROR: Missing function sum1toN.\n");
        printf("  Ensure Assembly.asm exports 'global sum1toN' and defines the procedure.\n");
        return 0;
    }

    struct {
        int input;
        int expected;
    } tests[] = {
        {0, 0},
        {1, 1},
        {5, 15},
        {10, 55},
        {20, 210},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int actual = sum1toN(tests[i].input);
        char details[128];
        snprintf(details, sizeof(details), "Called sum1toN(%d)", tests[i].input);
        success &= checkResult("sum1toN", tests[i].expected, actual, details);
    }

    return success;
}

int main(void) {
    int ok = 1;

    ok &= testAssemblyProcedure();
    ok &= testAnotherProcedure();
    ok &= testMaxOfThree();
    ok &= testSum1toN();

    if (ok) {
        printf("Successful\n");
        return 0;
    }

    return 1;
}
