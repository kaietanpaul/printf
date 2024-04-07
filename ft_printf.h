#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	c_specifier(int c);
int	id_specifier(int c);
int	s_specifier(char *c);
int	u_specifier(unsigned int c);
int	p_specifier(void *address);
int	x_specifier(unsigned long long c, char specifier);

#endif