#include <stdarg.h>
#include <unistd.h>

int	percent_specifier(const char *format, ...)
{
	va_list	arg_box;
	int	printed_chars;
	int	index;

	index = 0;
	printed_chars = 0;
	va_start(arg_box, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == '%')
		{
			printed_chars += write(1, "%", 1);
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
	percent_specifier("Hello, World!\n");
	percent_specifier("Character:2percents-%%%% %c %c 1percent-%% cc%%c\n", 'U', 'B', 'A', 'D');

	return (0);
}