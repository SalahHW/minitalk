/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:33:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/24 13:13:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	process_message(unsigned char c, int client_pid)
{
	static char	*message;

	if (!message)
		message = ft_calloc(1, 1);
	if (!message)
	{
		ft_printf("Error\n");
		exit(2);
	}
	message = join_char_to_string(message, c);
	if (!c)
	{
		if (ft_strlen(message) > 0)
		{
			ft_printf("%s\n", message);
			kill(client_pid, SIGUSR1);
		}
		free(message);
		message = NULL;
	}
}

static void	server_sig_handler(int sig_number, siginfo_t *siginfo, void *c)
{
	static int				bit_count;
	static unsigned char	buffer_char;

	(void)c;
	if (sig_number == SIGUSR2)
		buffer_char |= 1;
	bit_count++;
	if (bit_count != 8)
		buffer_char <<= 1;
	if (bit_count == 8)
	{
		process_message(buffer_char, siginfo->si_pid);
		bit_count = 0;
		buffer_char = 0;
	}
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sigusr1;
	struct sigaction	sigusr2;

	sigusr1.sa_sigaction = &server_sig_handler;
	sigusr2.sa_sigaction = &server_sig_handler;
	sigusr1.sa_flags = SA_SIGINFO;
	sigusr2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigusr1, NULL);
	sigaction(SIGUSR2, &sigusr2, NULL);
	ft_printf("Server running, PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
}
