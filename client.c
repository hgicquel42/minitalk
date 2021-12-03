/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:00:59 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 16:15:42 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal;

void	try_kill(int pid, int signal)
{
	usleep(100);
	if (kill(pid, signal) == -1)
		return (ft_putstr("ERROR 1\n"));
	pause();
	if (g_signal != signal)
		return (ft_putstr("ERROR 2\n"));
}

void	send_chr(int pid, char c)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (c >> (8 - i - 1) & 1)
			try_kill(pid, SIGUSR1);
		else
			try_kill(pid, SIGUSR2);
		i++;
	}
}

void	send_str(int pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		send_chr(pid, s[i++]);
	send_chr(pid, 0);
}

void	handler(int signal, siginfo_t *info, void *ctx)
{
	(void)info;
	(void)ctx;
	g_signal = signal;
}

int	main(int argc, char **argv)
{
	size_t				pid;
	struct sigaction	s;

	if (argc != 3)
		return (1);
	if (!ft_strlen(argv[1]))
		return (1);
	if (!ft_strlen(argv[2]))
		return (1);
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &s, 0))
		return (1);
	if (sigaction(SIGUSR2, &s, 0))
		return (1);
	pid = ft_atoui(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
