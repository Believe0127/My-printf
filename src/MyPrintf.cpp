#include <iostream>
#include <stdarg.h>

void printf_g(const char *format, ...) {
	va_list args;
	va_start(args, format);
	char buf[300] = {};

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
		case 'x':
			_itoa_s(va_arg(args, int), buf, 16);
			fputs(buf, stdout);
			break;
		case 'f':
			_gcvt_s(buf, va_arg(args, double), 16);
			fputs(buf, stdout);
			break;
		case 's':
			fputs(va_arg(args, const char *), stdout);
			break;
		case 'c':
			putchar(va_arg(args, char));
			break;
		default:
			std::cerr << __FUNCTION__ << ": 書式文字列 '" << *format << "' がありません\n";
			exit(EXIT_FAILURE);
		}
	}
	va_end(args);
}

int main() {
	printf_g("整数 : %d\n浮動小数点 : %f\n文字列 : %s\n文字: %c", 123, 1.23456, "Hello World!", 'C');
	return 0;
}