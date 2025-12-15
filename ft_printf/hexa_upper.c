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

int	hexa_upper(int num)
{
	unsigned int	casted_num;
	int				idx;
	char			*hexa;
	char			buff[9];

	idx = 0;
	casted_num = (unsigned int) num;
	hexa = "0123456789ABCDEF";
	if (num == 0)
		return (_putstr("0"));
	while (casted_num > 0)
	{
		buff[idx] = hexa[casted_num % 16];
		idx++;
		casted_num = casted_num / 16;
	}
	buff[idx] = '\0';
	rev_str(buff);
	return (_putstr(buff));
}
