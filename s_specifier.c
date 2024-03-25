#include <stdarg.h>
#include <unistd.h>

int	s_specifier(const char *format, ...)
{
	va_list	arg_box;
	int	printed_chars;
	int	index;
	int	i;
	char	*c;

	index = 0;
	i = 0;
	printed_chars = 0;
	va_start(arg_box, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == 's')
		{
			c = va_arg(arg_box, char *);
			if (c != NULL)
			{
				while (c[i])
				{
					printed_chars += write(1, &c[i], 1);
					i++;
				}
			}
			i = 0;
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
	s_specifier("Hello, World!\n");
	s_specifier("Character: %ss%%%c %% cc%%s    %s\n", "ABBA", "AHA");

	return (0);
}