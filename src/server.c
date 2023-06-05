/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:33:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/06 01:28:41 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	struct sigaction	sigusr1;
	struct sigaction	sigusr2;

	sigusr1.sa_handler = &sig_handler;
	sigusr2.sa_handler = &sig_handler;
	ft_printf("%d\n", getpid());
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

void	sig_handler(int sig_number)
{
	static int				bit_count;
	static unsigned char	buffer;

	if (sig_number == SIGUSR2)
	{
		buffer |= 1;
	}
	bit_count++;
	if (bit_count != 8)
		buffer <<= 1;
	if (bit_count == 8)
	{
		ft_printf("%c", buffer);
		bit_count = 0;
		buffer = 0;
	}
}
