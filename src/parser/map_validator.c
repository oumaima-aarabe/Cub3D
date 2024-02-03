/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:17:28 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/05 01:47:47 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int validate_file_name(char *name, char *extension)
{
    char **arr;
    int i;

    i = 0;
    if (!ft_strrchr(name, '.'))
        return (0);
    arr = ft_split(name, '.');
    while (arr[i])
        i++;
    --i;
    if (ft_strcmp(arr[i], extension))
        return (0);    
    
    return (1);
}

int validate_map_dims(t_map_data *data)
{
    char **__map;
    char *_line;
    char *line;
    int  h;

    h = 0;
    _line = data->mini_map[h];
    while (_line)
    {
        _line = data->mini_map[h++];
        line = ft_strtrim(_line, " \t\n");
        // printf("line : %s;\n", line);
        // printf("cond 1: %d\n", (line[0] != '1' || line[ft_strlen(line) - 1] != '1'));
        // printf("cond 2: %d\n", !(ft_strchr(line , '1') &&  != ft_strrchr(line , '1')) );
        if (!line || !ft_strlen(line))
            break;
        else if (!is_valid_line(line))
            return (0);
        if (ft_strlen(line) && (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
            // && !(ft_strchr(data->mini_map[h] , '1') != ft_strrchr(data->mini_map[h] , '1'))
            )
            return (0);
    }
    return (1);
}

int is_char_valide_space(char c)
{
    return (c == '1' || c == '0');
}

int check_space(char **map, int i, int j)
{
    if (map[i] && map[i][j])
    {
        if ((i > 0 && !is_char_valide_space(map[i - 1][j]))
        || map[i + 1] && !is_char_valide_space(map[i + 1][j])
        || !map[i + 1])
            return (0);
        else if ((j > 0 && !is_char_valide_space(map[i][j - 1]))
        || !is_char_valide_space(map[i][j + 1]))
            return (0);
        return (1);
    }
    return (0);
}


int validate_map_space(char **map)
{
    int x;
    int i;
    int y;

    i = 0;
    while (map[i])
    {
        y = 0;
        while (map[i][y])
        {
            if (map[i][y] == '0')
                if (!check_space(map, i, y))
                    return (0);
            y++;
        }
        i++;
    }
    return (1);
        
}

int validate_map(t_data *data)
{
    char **arr;
    
    if (!validate_file_name(data->map_filename, "cub"))
        return (
            ft_putstr_fd("Error: Map should be a .cub file", STDERR_FILENO),
            0
        );
    if (!validate_map_dims(data->map_data))
        return (
            ft_putstr_fd("Map is not valid", STDERR_FILENO),
            0
        );
    if (!validate_map_space(data->map_data->mini_map))
        return (
            ft_putstr_fd("Map should be closed by walls\n", STDERR_FILENO),
            0
        );
    // printf("test\n");
    return (1);
}
