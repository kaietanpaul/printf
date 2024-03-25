#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	arg_box;
	int	printed_chars;
	int	index;
	char	c;

	index = 0;
	printed_chars = 0;
	va_start(arg_box, format);
	c = va_arg(arg_box, int);

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			printed_chars += write(1, &c, 1);
			index++;
		}
		else
			printed_chars += write(1, &format[index], 1);
		index++;
		printed_chars++;
	}
	va_end(arg_box);
	return (printed_chars);
}

int main(void)
{
	ft_printf("Hello, World!\n");
	ft_printf("Character: %c %c %% c%c\n", 'U');
	return (0);
}