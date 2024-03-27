#include <stdarg.h>
#include <unistd.h>
#include "c_specifier.c"
#include "s_specifier.c"


static int check_specifier(va_list arg_box, char specifier) {
	int len;

	len = 0;
	if (specifier == 'c')
		len += c_specifier(va_arg(arg_box, int));
	else if (specifier == 's')
		len += s_specifier(va_arg(arg_box, char *));
	// else if (specifier == 'i' || specifier == 'd')
	// 	len += id_specifier(va_arg(arg_box, int));
	// else if (specifier == 'x' || specifier == 'X')
	// 	len += id_specifier(va_arg(arg_box, unsigned int));
	// else if (specifier == 'p')
	// 	len += p_specifier(va_arg(arg_box, unsigned int));
	return (len);
}

int ft_printf(const char *format, ...) {
	va_list arg_box;
	int index;
	int len;


	va_start(arg_box, format);

	index = 0;
	len = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			len += check_specifier(arg_box, format[index]);
		}
		else
			len += write(1, &format[index], 1);
		index++;
	}
	va_end(arg_box);
	return (len);
}

int	main(void)
{
	
	ft_printf("C: 1234%c6\n", 53);
	ft_printf("S: 1234%ssix\n", "five");

	return (0);
}