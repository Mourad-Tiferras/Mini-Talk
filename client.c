#include "mini.h"

int	*char_con(char c)
{
	static int	bin[8];
	int			idx;

	idx = 0;
	while (idx < 8)
	{
		bin[idx] = 0;
		idx++;
	}
	idx = 7;
	while (c > 0)
	{
		bin[idx] = c % 2;
		c = c / 2;
		idx--;
	}
	return (bin);
}

void	sender(char c, int pid)
{
	int	idx;
	int	*bin;

	idx = 0;
	bin = char_con(c);
	while (idx <= 7)
	{
		if (bin[idx] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(2000);
		usleep(2000);
		idx++;
	}
}

static int _notnumiric(char* str)
{
	size_t		idx;

	idx = 0;
	while (*(str + idx) != '\0')
	{
		if ((str[idx] < '0' && str[idx] > '9'))
			return (-1);
		idx++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	idx;

	if (argc != 3)
	{
		ft_putstr("+++Error+++\n./client [Server PID] MESSAGE\n");
		exit(1);
	}
	if (_notnumiric(argv[1]) == -1)
	{
		ft_putstr("+++Error+++\n./client [Server PID] MESSAGE\n   [Server PID] is a Positive INT");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		exit(1);
	idx = 0;
	while (argv[2][idx] != '\0')
	{
		sender(argv[2][idx], pid);
		idx++;
	}
	sender('\0', pid);
	ft_putstr("\n   Message sent\n");
	return (0);
}
