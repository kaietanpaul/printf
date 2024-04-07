#include "ft_printf.h"

int	p_specifier(void *address)
{
	int	printed_chars;

	printed_chars = 0;
	if (address == 0)
		return (printed_chars += write(1, "(nil)", 5));
	else
	{
		printed_chars += write(1, "0x", 2);
		printed_chars += x_specifier((unsigned long long)address, 'x');
	}
	return (printed_chars);
}