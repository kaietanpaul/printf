#include "ft_printf.h"

static int	check_specifier(va_list arg_box, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += c_specifier(va_arg(arg_box, int));
	else if (specifier == 's')
		len += s_specifier(va_arg(arg_box, char *));
	else if (specifier == '%')
		len = write(1, "%", 1);
	else if (specifier == 'i' || specifier == 'd')
		len += id_specifier(va_arg(arg_box, int));
	else if (specifier == 'x' || specifier == 'X')
		len += x_specifier(va_arg(arg_box, unsigned int), specifier);
	else if (specifier == 'u')
		len += u_specifier(va_arg(arg_box, unsigned int));
	else if (specifier == 'p')
		len += p_specifier(va_arg(arg_box, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_box;
	int		index;
	int		len;

	va_start(arg_box, format);
	index = 0;
	len = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			len += check_specifier(arg_box, format[index + 1]);
			index++;
		}
		else
			len += write(1, &format[index], 1);
		index++;
	}
	va_end(arg_box);
	return (len);
}