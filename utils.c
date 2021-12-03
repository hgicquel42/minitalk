/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:14:00 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 13:26:33 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_atoui(char *s)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i] >= '0' && s[i] <= '9')
		x = (x * 10) + (s[i++] - '0');
	return (x);
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putui(size_t n)
{
	if (n >= 10)
		ft_putui(n / 10);
	ft_putchr((n % 10) + '0');
}
