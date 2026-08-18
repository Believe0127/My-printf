#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buf[300]{};

    for (; *format; ++format) {
        if (*format != '%') {
            putchar(*format);
            continue;
        }
        switch (*++format) {
        case 'd':
            _itoa_s(va_arg(args, int), buf, 10);
            fputs(buf, stdout);
            break;
        case 'u':
            _ultoa_s(va_arg(args, unsigned int), buf, 10);
            fputs(buf, stdout);
            break;
        case 'x':
            _itoa_s(va_arg(args, int), buf, 16);
            fputs(buf, stdout);
            break;
        case 'f':
            _gcvt_s(buf, va_arg(args, double), 16);
            fputs(buf, stdout);
            break;
        case 's':
            fputs(va_arg(args, const char*), stdout);
            break;
        case 'c':
            putchar(va_arg(args, char));
            break;
        default:
            fprintf_s(stderr, "%s: 書式文字列 '%c' がありません\n", __FUNCTION__, *format);
            exit(EXIT_FAILURE);
            break;
        }
    }
    va_end(args);
}

int main() {
    my_printf("signed int        : %d\n", -123);
    my_printf("unsigned int      : %u\n", 123);
    my_printf("hex (unsigned int): %x\n", 0x3308A5D0);
    my_printf("float             : %f\n", 1.23456789);
    my_printf("string            : %s\n", "Hello World!");
    my_printf("charactor         : %c\n", 'A');

    return 0;
}
