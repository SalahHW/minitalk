/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:46:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/06/13 07:47:21 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
