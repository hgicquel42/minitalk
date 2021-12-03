/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:00:59 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 13:28:38 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_chr(int pid, char c)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (c >> (8 - i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	if (!ft_strlen(argv[1]))
		return (1);
	if (!ft_strlen(argv[2]))
		return (1);
	pid = ft_atoui(argv[1]);
	ft_putui(pid);
	ft_putchr('\n');
	send_str(pid, argv[2]);
}
