/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:16:45 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/06 01:29:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong use of the client : ", 2);
		ft_putstr_fd("./client \"server PID\" \"message\"\n", 2);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	send_bits_from_char(server_pid, *argv[2]);
}

void	send_bits_from_char(int pid, unsigned char c)
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
