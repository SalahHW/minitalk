/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:33:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/13 12:08:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_acknowledge(char c, int *flag)
{
	int			pid;
	static char	*pid_string;

	if (!pid_string)
		pid_string = ft_calloc(1, 1);
	pid_string = join_char_to_string(pid_string, c);
	if (!c)
	{
		pid = ft_atoi(pid_string);
		free(pid_string);
		pid_string = 0;
		kill(pid, SIGUSR2);
		*flag = 0;
	}
}

static void	process_message(char c, int *flag)
{
	static char	*message;

	if (!message)
		message = ft_calloc(1, 1);
	message = join_char_to_string(message, c);
	if (!c)
	{
		if (ft_strlen(message) > 0)
			ft_printf("%s\n", message);
		free(message);
		message = NULL;
		*flag = 1;
	}
}

static void	server_sig_handler(int sig_number)
{
	static int	bit_count;
	static char	buffer_char;
	static int	flag;

	if (sig_number == SIGUSR2)
		buffer_char |= 1;
	bit_count++;
	if (bit_count != 8)
		buffer_char <<= 1;
	else
	{
		if (!flag)
			process_message(buffer_char, &flag);
		else
			send_acknowledge(buffer_char, &flag);
		bit_count = 0;
		buffer_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sigusr1;
	struct sigaction	sigusr2;

	sigusr1.sa_handler = &server_sig_handler;
	sigusr2.sa_handler = &server_sig_handler;
	ft_printf("Server running, PID : %d\n", getpid());
	ft_printf("Waiting for input :\n");
	ft_printf("________________________\n");
	while (1)
	{
		sigaction(SIGUSR1, &sigusr1, NULL);
		sigaction(SIGUSR2, &sigusr2, NULL);
		pause();
	}
}
