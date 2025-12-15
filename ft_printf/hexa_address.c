#include "ft_printf.h"

static char	*rev_str(char *str)
{
	int		idx;
	int		last_idx;
	char	tmp;

	idx = 0;
	if (str == NULL || str[0] == '\0')
		return (NULL);
	last_idx = _strlen(str) - 1;
	while (str[idx] != '\0' && (idx < last_idx))
	{
		tmp = str[idx];
		str[idx] = str[last_idx];
		str[last_idx] = tmp;
		idx++;
		last_idx--;
	}
	return (str);
}

int	hexa_address(unsigned long int num)
{
	int				idx;
	char			*hexa;
	char			buff[17];

	idx = 0;
	hexa = "0123456789abcdef";
	if (num == 0)
		return (_putstr("0x0"));
	if (_putstr("0x") < 0)
		return (-1);
	while (num > 0)
	{
		buff[idx] = hexa[num % 16];
		idx++;
		num = num / 16;
	}
	buff[idx] = '\0';
	rev_str(buff);
	if (_putstr(buff) < 0)
		return (-1);
	return (_strlen(buff) + 2);
}
