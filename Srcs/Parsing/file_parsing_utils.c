/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:24 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/04 15:53:19 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_floor_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "F ", 2))
	{
		i += 2;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
        if (!game->data.floor_color)
		{
			game->data.floor_color = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.floor_color[j++] = line[i++];
			game->data.floor_color[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nToo many floor colors\n", 2);
			exit(1);
		}
	}
}

void	_ceiling_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "C ", 2))
	{
		i += 2;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
        if (!game->data.ceiling_color)
		{
			game->data.ceiling_color = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.ceiling_color[j++] = line[i++];
			game->data.ceiling_color[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nToo many Ceiling colors\n", 2);
			exit(1);
		}
	}
}

void	_char_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i] == '\0')
		return ;
	if (ft_strncmp(line, "NO ", 3) && ft_strncmp(line, "SO ", 3)
		&& ft_strncmp(line, "EA ", 3) && ft_strncmp(line, "WE ", 3)
		&& ft_strncmp(line, "C ", 2) && ft_strncmp(line, "F ", 2))
	{
		ft_putstr_fd("Error\nInvalid character in file\n", 2);
		exit(1);
	}
}

void	_verify(t_game *game, int i)
{
	int		start;
	char	*line;
	int		last;

	start = _emptylines(game, i) - 1;
	last = -1;
	while (game->data.file[start++])
	{
		line = game->data.file[start];
		if (!_line_empty(line))
			last = start;
		else if (last != -1)
			break ;
		if (_is_invalid(line, game))
		{
			ft_putstr_fd("Error\nInvalid character in map\n", 2);
			exit(1);
		}
	}
	_after_map(game, last);
	if (i == start || game->player.p_count != 1 || last == -1)
	{
		ft_putstr_fd("Error\nInvalid file format\n", 2);
		exit(1);
	}
}

int	_is_invalid(char *line, t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == 'S')
			game->player.p_count++;
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '0'
			&& line[i] != '1' && line[i] != '\n')
			return (1);
		flag++;
		i++;
	}
	return (0);
}
