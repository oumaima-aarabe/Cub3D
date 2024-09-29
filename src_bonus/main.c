/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:42:19 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 23:51:11 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser/parser.h"
#include "render/render.h"

int	init_game(char **av, t_data **data)
{
	*data = ft_calloc(1, sizeof(t_data));
	if (!*data)
		return (0);
	if (!parse_args(av, *data))
		return (0);
	return (render_window(*data));
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac >= 2)
	{
		if (!init_game(av, &data))
			return (ft_putstr_fd("Error\n", STDERR_FILENO), \
clean_exit(data), 500);
	}
	else
		ft_putstr_fd("Should pass map file as argument\n", STDERR_FILENO);
	return (0);
}
