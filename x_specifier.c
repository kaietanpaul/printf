#include <stdarg.h>
#include <unistd.h>

static void print_hex_recursive(unsigned int n, int *printed_chars) {
	char *hex_digits = "0123456789abcdef";

	if (n >= 16) {
		print_hex_recursive(n / 16, printed_chars);
	}
	*printed_chars += write(1, &hex_digits[n % 16], 1);
}

int x_specifier(const char *format, ...) {
	va_list arg_box;
	int printed_chars = 0;
	int index = 0;
	unsigned int u;

	va_start(arg_box, format);

	while (format[index] != '\0') {
		if (format[index] == '%' && format[index + 1] == 'x') {
			u = va_arg(arg_box, unsigned int);
			print_hex_recursive(u, &printed_chars);
			index++;
		} else {
			printed_chars += write(1, &format[index], 1);
		}
		index++;
	}

	va_end(arg_box);

	return printed_chars;
}

int main(void) {
	x_specifier("Hello, World!\n");
	x_specifier("Hexadecimal: %x\n", 9);

	return 0;
}
