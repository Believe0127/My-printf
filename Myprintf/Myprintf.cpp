#include <iostream>
#include <stdarg.h>

void printf_g(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buf[300] = {};

    for (;*format; ++format) {
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
            fprintf(stderr, "%s: 書式文字列 '%c' がありません\n", __FUNCTION__, *format);
            exit(EXIT_FAILURE);
        }
    }
    va_end(args);
}

int main() {
    printf_g("符号付き整数 : %d\n", -123);
    printf_g("符号なし整数 : %d\n", 123);
    printf_g("16進数 : %x\n", 0x3308A5D0);
    printf_g("浮動小数点 : %f\n", 1.23456789);
    printf_g("文字列 : %s\n", "Hello World!");
    printf_g("文字 : %c", 'A');

    return 0;
}
