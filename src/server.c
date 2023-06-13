/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:33:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/13 08:25:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	struct sigaction	sigusr1;
	struct sigaction	sigusr2;

	sigusr1.sa_handler = &sig_handler;
	sigusr2.sa_handler = &sig_handler;
	ft_printf("Server running, PID : %d\n", getpid());
	ft_printf("Waiting for input :\n");
	ft_printf("________________________\n");
	while (1)
	{
		sigaction(SIGUSR1, &sigusr1, NULL);
		sigaction(SIGUSR2, &sigusr2, NULL);
	}
}

void	process_message(char c)
{
	static char *message;

	if (!message)
		message = ft_calloc(1, 1);
	message = join_char_to_string(message, c);
	if (!c)
	{
		if (ft_strlen(message) > 0)
			ft_printf("%s\n", message);
		free(message);
		message = NULL;
	}
}

void	sig_handler(int sig_number)
{
	static int	bit_count;
	static char	buffer_char;
	static char	*buffer_string;

	if (sig_number == SIGUSR2)
		buffer_char |= 1;
	bit_count++;
	if (bit_count != 8)
		buffer_char <<= 1;
	else
	{
		process_message(buffer_char);
		bit_count = 0;
		buffer_char = 0;
	}
}
