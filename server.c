#include "mini.h"

static void	put_char(char c)
{
	write(1, &c, 1);
}

void	_reset(int *binary, int *n)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		binary[idx] = 0;
		idx++;
	}
	*n = 0;
}

static void	norm(int *pid, int sender_pid, int *idx, int *binnary)
{
	if (pid == 0)
		*pid = sender_pid;
	if (*pid != sender_pid)
	{
		_reset(binnary, idx);
		*pid = sender_pid;
		ft_putstr("\n\n\n\n");
	}
}

void	handler(int signum, siginfo_t *sender_info, void *ucontext)
{
	static int	bin[8];
	static int	idx = 0;
	char		c;
	static int	client_pid;

	(void) (ucontext);
	norm(&client_pid, sender_info->si_pid, &idx, bin);
	if (signum == SIGUSR1)
		bin[idx] = 1;
	else if (signum == SIGUSR2)
		bin[idx] = 0;
	idx++;
	if (idx == 8)
	{
		c = bin_to_decimal(bin);
		if (c == '\0')
		{
			put_char('\n');
			_reset(bin, &idx);
			return ;
		}
		else
			put_char(c);
		_reset(bin, &idx);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void) (argv);
	if (argc != 1)
	{
		ft_putstr("No argument needed for ./server\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("====================\n The Server PID = %d\n", pid);
	ft_putstr("\n====================\n");
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Waiting for messages ...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
