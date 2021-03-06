/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:27:38 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/13 15:57:58 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_valid_identifier(char *line)
{
	if (line[0] == 'R' || line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
	|| line[0] == 'E' || line[0] == 'F' || line[0] == 'C' || line[0] == '1'
	|| line[0] == ' ' || line[0] == '\0')
		return (1);
	return (0);
}

int		is_wall(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int		is_valid_color(int red, int green, int blue)
{
	if (red > 255 || green > 255 || blue > 255)
		return (0);
	if (red == -1 || green == -1 || blue == -1)
		return (0);
	return (1);
}

int		is_valid_elem(char **map, int x, int y)
{
	if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != '2'
	&& map[x][y] != ' ' && map[x][y] != 'N' && map[x][y] != 'S'
	&& map[x][y] != 'W' && map[x][y] != 'E')
		return (0);
	return (1);
}
