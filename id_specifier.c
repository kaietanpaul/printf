#include <unistd.h>
#include <stdio.h>

static	int edge_case(int c)
{
	if (c == 0)
		return write(1, "0", 1);
	else if (c == -2147483648)
		return write(1, "-2147483648", 11);
	return 0;
}

int	id_specifier(int c)
{
	int	printed_chars;
	char	new_num;

	printed_chars = 0;
	printed_chars += edge_case(c);
	if (printed_chars > 0)
		return (printed_chars);
	if (c < 0)
	{
		c = -c;
		printed_chars += write(1, "-", 1);
		printed_chars += id_specifier(c);
	}
	else if (c > 9)
	{
		new_num = c % 10 + '0';
		c /= 10;
		printed_chars += id_specifier(c);
		printed_chars += write(1, &new_num, 1);
	}
	else
	{
		new_num = c % 10 + '0';
		printed_chars += write(1, &new_num, 1);
	}
	return (printed_chars);
}

int	main(void)
{
	int	printed_chars;

	printed_chars = id_specifier(-4535);
	printf("\n%d\n", printed_chars);
	return (0);
}
