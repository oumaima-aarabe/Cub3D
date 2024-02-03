/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:36:18 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/05 01:11:23 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

	# include "../cub3d.h"
	# include "../utils/utils.h"

	int		init_game(char **av, t_data **data);
	int		parse_args(char **av, t_data *data);

	int		is_configuration_valid(t_textures_data *data);
	int		parse_configuration(int fd, t_data *data, int *r_lines);

	/*      			Texutres				*/

	int		parse_texture_line(char *line, t_textures_data *data);
	int		get_texture_conf(char *line, t_textures_data *data);
	int		load_textures(t_data *data);
	
	/*      			Colors		 	         */
	
	int		parse_rgb(char *s, char type, t_textures_data *data);
	int		validate_colors_line(char **arr);
	int		parse_color_line(char *line, t_textures_data *data);

	/*      			Map			 	         */
	void detect_player(t_data * data);
	int is_index_player(char c);

	int		allocate_map(int r_count, t_data *data);
	int		parse_map(int fd, t_data *data, int *r_lines);
	void	fill_map(char *_line ,int fd, t_map_data *data);
	void    set_player_onmap(int i, int c, int vert, char *line, t_map_data *data);

	int 	validate_file_name(char *name, char *extension);
	int		is_valid_space(char c);
	int		is_valid_line(char *l);
	int		validate_map(t_data *data);
	void	fill_map_space(t_map_data *data);
#endif