#include <unistd.h>

int	s_specifier(char *c)
{
	int	index;
	int	printed_chars;

	index = 0;
	printed_chars = 0;
	while (c[index] != '\0')
	{
		printed_chars += write(1, &c[index], 1);
		index++;
	}
	return (printed_chars);
}