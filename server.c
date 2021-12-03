/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:50:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 16:28:48 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_state {
	char	*s;
	char	c;
	size_t	i;
}	t_state;

t_state	g_state;

char	*ft_stra(char *s, char c)
{
	size_t	i;
	size_t	l;
	char	*r;

	l = 0;
	while (s && s[l])
		l++;
	r = malloc(l + 2);
	if (!r)
		return (0);
	i = -1;
	while (s && s[++i])
		r[i] = s[i];
	r[i++] = c;
	r[i++] = 0;
	return (r);
}

void	try_kill(int pid, int signal)
{
	usleep(100);
	if (kill(pid, signal) == -1)
		return (ft_putstr("ERROR 1\n"));
}

void	handler(int signal, siginfo_t *info, void *ctx)
{
	(void)ctx;
	g_state.c <<= 1;
	g_state.c |= (signal == SIGUSR1);
	try_kill(info->si_pid, signal);
	if (++g_state.i < 8)
		return ;
	if (g_state.c)
		g_state.s = ft_stra(g_state.s, g_state.c);
	else
		ft_putstr(g_state.s);
	g_state.i = 0;
	g_state.c = 0;
}

int	main(void)
{
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &s, 0))
		return (1);
	if (sigaction(SIGUSR2, &s, 0))
		return (1);
	ft_putui(getpid());
	ft_putchr('\n');
	while (1)
		pause();
	return (0);
}
