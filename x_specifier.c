#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static int	print_hex(unsigned int c, char hex_chars[])
{
	int		printed_chars;
	int		reminder;
	char	hex_digit;

	reminder = 0;
	printed_chars = 0;
	if (c > 0)
	{
		reminder = c % 16;
		printed_chars += print_hex(c / 16, hex_chars);
	}
	if (reminder != 0)
	{
		hex_digit = hex_chars[reminder];
		printed_chars += write(1, &hex_digit, 1);
	}
	return (printed_chars);
}

int	x_specifier(unsigned int c, char specifier)
{
	int			printed_chars;
	static char	small_hex[] = "0123456789abcdef";
	static char	large_hex[] = "0123456789ABCDEF";

	printed_chars = 0;
	if (c == 0)
	{
		printed_chars += write(1, "0", 1);
		return (printed_chars);
	}
	if (specifier == 'x')
		printed_chars += print_hex(c, small_hex);
	else
		printed_chars += print_hex(c, large_hex);
	return (printed_chars);
}