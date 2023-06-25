/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:20:01 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/26 01:11:32 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>

//		parser.c
void	parse(int argc, char **argv);
//		error.c
void	exit_error(void);
void	exit_arg_error(void);
void	exit_pid_error(void);
void	exit_time_out(void);
//		utils.c
char	*join_char_to_string(char *str, unsigned char c);

#endif
