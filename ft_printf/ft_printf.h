#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		_strlen(const char *s);
int		_putchar(char c);
int		_putstr(char *s);
int		_putnbr(int n);
int		print_unsigned(unsigned int n);
int		hexa_lower(int num);
int		hexa_upper(int num);
int		hexa_address(unsigned long int num);
int		ft_printf(const char *format, ...);

#endif
