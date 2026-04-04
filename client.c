/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 10:09:59 by anasimi           #+#    #+#             */
/*   Updated: 2026/03/21 10:10:24 by anasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	ft_ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	ft_send_signal(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		write(2, "Failed to send signal\n", 22);
		exit(1);
	}
}

static void	ft_send_bits(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if ((c & (0x01 << bit)) != 0)
			ft_send_signal(pid, SIGUSR1);
		else
			ft_send_signal(pid, SIGUSR2);
		while (g_ack == 0)
			usleep(500000);
		bit++;
	}
}

static void	ft_send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		ft_send_bits(pid, (unsigned char)msg[i]);
		i++;
	}
	ft_send_bits(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <MESSAGE>\n", 32), 1);
	pid = ft_get_pid(argv[1]);
	if (pid == 0)
		return (1);
	if (!ft_init_client_signals(&sa))
		return (write(2, "sigaction error\n", 16), 1);
	ft_send_message(pid, argv[2]);
	return (0);
}
