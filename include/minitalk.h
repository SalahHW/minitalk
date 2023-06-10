/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:20:01 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/10 02:52:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>

void	sig_handler(int signal);
void	send_message(int server_pid, char *message);
void	send_bits_from_char(int pid, unsigned char c);
//		parser.c
void	parse(int argc, char **argv);
//		error.c
void	exit_arg_error(void);
void	exit_pid_error(void);

#endif
