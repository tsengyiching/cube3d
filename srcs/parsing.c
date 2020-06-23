/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:15:15 by yictseng          #+#    #+#             */
/*   Updated: 2020/06/23 22:12:18 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		is_valid_char(char *line)
{
	if (line[0] == 'R'|| line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
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

int		find_element(t_config *cfg, t_mlx *mlx, char *line)
{
	int		error_code;
	
	if (!is_valid_char(line))
		return (-2);
	if (line[0] == 'R')
	{
		if ((error_code = get_resolution(cfg, line)) < 0)
			return (error_code);
	}
	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E' || line[0] == 'C' || line[0] == 'F')
	{
		if ((error_code = parse_texture(cfg, mlx, line)) < 0)
			return (error_code);
	}
	else if (line[0] == '1' || line[0] == ' ')
	{
		error_code = 2;
		return (error_code);
	}
	return (1);
}

int		parsing(int fd, t_config *cfg, t_mlx *mlx)
{
	char	*line;
	char	**tab;
	int		ret;
	int		error_code;

	ret = 1;
	tab = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		error_code = find_element(cfg, mlx, line);
		if (error_code < 0)
			return (error_code);
		if (error_code == 2)
			break ;
		free(line);
		line = NULL;
	}
	while (ret > 0)
	{
		if (line != NULL)
		{
			if (!(cfg->map = malloc(sizeof(char *) * 2)))
				return (-9);
			if (!(cfg->map[0] = ft_strdup(line)))
				return (-9);
			cfg->map[1] = NULL;
			free(line);
			line = NULL;
		}
		ret = get_next_line(fd, &line);
		tab = cfg->map;
		cfg->map = ft_add_line_in_tab(line, tab);
		free(line);
		line = NULL;
	}
	return (1);
}