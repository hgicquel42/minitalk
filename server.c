/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:50:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 13:28:17 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_state {
	char	c;
	size_t	i;
}	t_state;

t_state	g_state;

void	handler(int signal, siginfo_t *info, void *ctx)
{
	(void)ctx;
	g_state.c |= (signal == SIGUSR2);
	g_state.c <<= 1;
	if (g_state.i++ < 8)
		return ;
	write(1, &g_state.c, 1);
	g_state.i = 0;
	g_state.c = 0;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s;

	ft_putui(getpid());
	ft_putchr('\n');
	s.sa_flags = SIGINFO;
	s.sa_sigaction = handler;
	sigaction(SIGUSR1, &s, 0);
	while (1)
		pause();
	return (0);
}
