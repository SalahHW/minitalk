/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:30:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/24 20:31:42 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	exit_arg_error(void)
{
	ft_printf("Wrong use of the client : \n");
	ft_printf("./client \"server PID\" \"message\"\n");
	exit(1);
}

void	exit_pid_error(void)
{
	ft_printf("Wrong PID :\n");
	ft_printf("PID must be not null positive integer\n");
	exit(1);
}
