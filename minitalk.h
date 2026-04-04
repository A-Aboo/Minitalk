/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <anasimi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 10:56:54 by anasimi           #+#    #+#             */
/*   Updated: 2026/04/04 10:56:56 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_ack;

int		ft_atoi(const char *str);
int		ft_get_pid(char *str);
int		ft_init_client_signals(struct sigaction *sa);
void	ft_ack_handler(int sig);
void	ft_putnbr(int n);

#endif