#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

int sum_them_all(const unsigned int n, ...) {
    if (n == 0) {
        return 0;
    }

    int sum = 0;
    unsigned int i; // Move the loop counter variable declaration to the top

    va_list args;
    va_start(args, n);

    for (i = 0; i < n; i++) { // Use a separate line for loop declaration
        int value = va_arg(args, int);
        sum += value;
    }

    va_end(args);
    return sum;
}

