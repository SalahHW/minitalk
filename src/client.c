/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:16:45 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/24 19:51:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int			g_sig_pending;
static void	send_bits_from_char(int pid, unsigned char c)
{
	int	bit_count;

	bit_count = 7;
	while (bit_count >= 0)
	{
		g_sig_pending = 1;
		if (1 & c >> bit_count)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_sig_pending)
			;
		bit_count--;
	}
}

static void	client_sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received\n");
	else
		g_sig_pending = 0;
}

static void	send_message(int server_pid, char *message)
{
	while (*message)
	{
		send_bits_from_char(server_pid, *message);
		message++;
	}
	send_bits_from_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction usr1;
	struct sigaction usr2;
	int		server_pid;
	char	*argv_ptr;

	g_sig_pending = 0;
	usr1.sa_handler = &client_sig_handler;
	usr2.sa_handler = &client_sig_handler;
	parse(argc, argv);
	server_pid = ft_atoi(argv[1]);
	argv_ptr = argv[2];
	sigaction(SIGUSR1, &usr1, NULL);
	sigaction(SIGUSR2, &usr2, NULL);
	send_message(server_pid, argv_ptr);
}
