#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_strings(const char *separator, const unsigned int n, ...) {
    va_list args;
    va_start(args, n);

    for (unsigned int i = 0; i < n; i++) {
        const char *str = va_arg(args, const char *);
        
        if (str != NULL) {
            printf("%s", str);
        } else {
            printf("(nil)");
        }

        if (i < n - 1 && separator != NULL) {
            printf("%s", separator);
        }
    }

    va_end(args);
    printf("\n");
}

