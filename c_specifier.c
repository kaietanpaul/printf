#include <unistd.h>

int	c_specifier(int c)
{
	return (write(1, &c, 1));
}