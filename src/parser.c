/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:09:43 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/10 03:01:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	parse(int argc, char **argv)
{
	char	*argv_ptr;

	if (argc != 3)
		exit_arg_error();
	argv_ptr = argv[1];
	if (*argv_ptr == '0')
		exit_pid_error();
	while (*argv_ptr)
	{
		if (!ft_isdigit(*argv_ptr))
			exit_pid_error();
		argv_ptr++;
	}
}
