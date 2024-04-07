#include "ft_printf.h"

int	u_specifier(unsigned int c)
{
	unsigned int	printed_chars;
	unsigned char	new_num;

	printed_chars = 0;
	if (c == 0)
		return (printed_chars += write(1, "0", 1));
	else
	{
		if (c > 9)
			printed_chars += u_specifier(c / 10);
		new_num = c % 10 + '0';
		printed_chars += write(1, &new_num, 1);
	}
	return (printed_chars);
}