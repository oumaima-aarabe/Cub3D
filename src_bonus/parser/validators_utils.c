/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:52:15 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:34:40 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_space(char c)
{
	return (c == '0' || c == '1' || c == 'E'
		|| c == 'W' || c == 'N' || c == 'S'
		|| c == ' ' || c == '\t');
}

int	is_valid_line(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		if (!is_valid_space(l[i++]))
			return (0);
	return (1);
}
