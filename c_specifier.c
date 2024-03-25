#include <stdarg.h>
#include <unistd.h>

int	c_specifier(const char *format, ...)
{
	va_list	arg_box;
	int	printed_chars;
	int	index;
	char	c;

	index = 0;
	printed_chars = 0;
	va_start(arg_box, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			c = va_arg(arg_box, int);
			printed_chars += write(1, &c, 1);
			index++;
		}
		else
			printed_chars += write(1, &format[index], 1);
		index++;
	}

	va_end(arg_box);

	return (printed_chars);
}

int main(void)
{
	c_specifier("Hello, World!\n");
	c_specifier("Character: %c %c %% cc%%c\n", 'U', 'B', 'A', 'D');

	return (0);
}