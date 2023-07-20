#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_all(const char * const format, ...) {
    va_list args;
    va_start(args, format);

    char c;
    int i;
    double d;
    char *s;
    int printed = 0;

    const char *ptr = format;

    while (*ptr != '\0') {
        switch (*ptr) {
            case 'c':
                c = va_arg(args, int);
                if (printed > 0)
                    printf(", ");
                printf("%c", c);
                printed = 1;
                break;
            case 'i':
                i = va_arg(args, int);
                if (printed > 0)
                    printf(", ");
                printf("%d", i);
                printed = 1;
                break;
            case 'f':
                d = va_arg(args, double);
                if (printed > 0)
                    printf(", ");
                printf("%f", d);
                printed = 1;
                break;
            case 's':
                s = va_arg(args, char *);
                if (printed > 0)
                    printf(", ");
                if (s != NULL) {
                    printf("%s", s);
                } else {
                    printf("(nil)");
                }
                printed = 1;
                break;
            default:
                break;
        }
        ptr++;
    }

    va_end(args);
    printf("\n");
}
