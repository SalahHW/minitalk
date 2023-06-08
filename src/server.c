/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:33:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/07 00:48:49 by sbouheni         ###   ########.fr       */
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

void	ft_print_memory(char c)
{
	for (int i = 7; i >= 0; i--)
	{
		ft_putchar_fd((c & (1 << i)) ? '1' : '0', 0);
	}
	ft_printf("\n");
}

char	*join_char_to_string(char *str, unsigned char c)
{
	char	*new_string;
	char	*new_string_ptr;

	if (!str && !c)
		return (NULL);
	new_string = ft_calloc(ft_strlen(str) + 2, 1);
	if (!new_string)
		return (NULL);
	new_string_ptr = new_string;
	while (*str)
		*new_string_ptr++ = *str++;
	*new_string_ptr = c;
	return (new_string);
}

void	sig_handler(int sig_number)
{
	static int	bit_count;
	static char	buffer_char;
	static char	*buffer_string;

	if (sig_number == SIGUSR2)
	{
		buffer_char |= 1;
	}
	bit_count++;
	if (bit_count != 8)
		buffer_char <<= 1;
	else
	{
		if (!buffer_string)
			buffer_string = ft_calloc(1, 1);
		buffer_string = join_char_to_string(buffer_string, buffer_char);
		if (!buffer_char)
		{
			ft_printf("%s\n", buffer_string);
			free(buffer_string);
			buffer_string = NULL;
		}
		bit_count = 0;
		buffer_char = 0;
	}
}
