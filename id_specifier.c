#include <unistd.h>
#include <stdio.h>

static int	edge_case(int c)
{
	if (c == 0)
		return (write(1, "0", 1));
	else if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	return (0);
}

static int	print_digits(int c)
{
	int		printed_chars;
	char	new_num;

	printed_chars = 0;
	if (c > 9)
		printed_chars += print_digits(c / 10);
	new_num = c % 10 + '0';
	printed_chars += write(1, &new_num, 1);
	return (printed_chars);
}

int	id_specifier(int c)
{
	int	printed_chars;

	printed_chars = edge_case(c);
	if (printed_chars > 0)
		return (printed_chars);
	if (c < 0)
	{
		c = -c;
		printed_chars += write(1, "-", 1);
	}
	printed_chars += print_digits(c);
	return (printed_chars);
}