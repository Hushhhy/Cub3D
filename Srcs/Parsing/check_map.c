/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:04:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/09 14:53:38 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_check_the_map(t_game *game)
{
	if (!game->data.map)
	{
		ft_putstr_fd("Error\nMap not found\n", 2);
		exit(1);
	}
	if (_get_map_height(game->data.map) < 3)
	{
		ft_putstr_fd("Error\nMap too small\n", 2);
		exit(1);
	}
	if (!_check_nb_player(game->data.map))
	{
		ft_putstr_fd("Error\nNo or too many players\n", 2);
		exit(1);
	}
	if (!_check_closed_map(game))
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		exit(1);
	}
}

bool	_check_closed_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	if (!_check_top_bot(game->data.map[i]))
		return (false);
	while (game->data.map[++i])
	{
		j = 0;
		while (game->data.map[i][j])
		{
			if (game->data.map[i][j] == '0')
			{
				if (!_there_is_walls(game->data.map, i, j))
					return (false);
			}
			j++;
		}
	}
	if (!_check_top_bot(game->data.map[i - 1]))
		return (false);
	return (true);
}

bool	_there_is_walls(char **map, int y, int x)
{
	if (!_check_rows(map, y, x))
		return (false);
	if (!_check_cols(map, y, x))
		return (false);
	return (true);
}

bool	_check_rows(char **map, int y, int x)
{
	int	i;

	i = x;
	while (i >= 0)
	{
		printf("left = %c\n", map[y][i]);
		if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
			&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0' && map[y][i] != ' ')
			return (false);
		else if (map[y][i] == '1')
			break ;
		else if (map[y][i] == ' ')
			if (!_there_is_walls(map, y, i))
				return (false);
		i--;
	}
	i = x;
	while (map[y][i])
	{
		printf("right = %c\n", map[y][i]);
		if (map[y][i] != '1' && map[y][i] != 'N' && map[y][i] != 'S'
			&& map[y][i] != 'E' && map[y][i] != 'W' && map[y][i] != '0' && map[y][i] != ' ')
			return (false);
		if (map[y][i] == '1')
			break ;
		if (map[y][i] == ' ')
			_there_is_walls(map, y, i);
		i++;
	}
	return (true);
}

bool	_check_cols(char **map, int y, int x)
{
	int	i;

	i = y;
	while (i >= 0)
	{
		if (map[i][x] == ' ')
			_there_is_walls(map, i, x);
		else if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
			&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0')
			return (false);
		i--;
	}
	i = y;
	while (map[i])
	{
		if (map[i][x] == ' ')
			_there_is_walls(map, i, x);
		else if (map[i][x] != '1' && map[i][x] != 'N' && map[i][x] != 'S'
			&& map[i][x] != 'E' && map[i][x] != 'W' && map[i][x] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	_check_top_bot(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		if (line[i] == '\n')
			return (true);
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}




