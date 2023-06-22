/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:16:45 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/14 01:18:12 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_bits_from_char(int pid, unsigned char c)
{
	int	bit_count;

	bit_count = 7;
	while (bit_count >= 0)
	{
		if (1 & c >> bit_count)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_count--;
		usleep(100);
	}
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
	int		server_pid;
	char	*argv_ptr;

	parse(argc, argv);
	server_pid = ft_atoi(argv[1]);
	argv_ptr = argv[2];
	send_message(server_pid, argv_ptr);
}
