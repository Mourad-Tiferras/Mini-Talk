#include "ft_printf.h"

static int	handle_more(int n)
{
	int		div;
	int		count;
	char	result;

	div = 10;
	count = 0;
	while ((n / div) >= 10)
	{
		div = div * 10;
	}
	while (div > 0)
	{
		result = (((n / div)) + '0');
		count += write(1, &result, 1);
		n = n % div;
		div = div / 10;
	}
	return (count);
}

int	_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
		count++;
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
		count++;
		return (count);
	}
	count += handle_more(n);
	return (count);
}
