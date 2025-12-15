#ifndef MINI_H
# define MINI_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		bin_to_decimal(int *bin);
void	_reset(int *binary, int *n);
int		ft_printf(const char *format, ...);

#endif
