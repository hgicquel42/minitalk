/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:50:42 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/03 16:29:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);

size_t	ft_atoui(char *s);

void	ft_putchr(char c);

void	ft_putstr(char *s);

void	ft_putui(size_t n);

void	try_kill(int pid, int signal);

#endif