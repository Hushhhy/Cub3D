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
			if (game->data.map[i][j] == '0' || game->data.map[i][j] == ' ')
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

bool	_there_is_walls(char **map, int row, int col)
{
	if (!_check_rows(map, row))
		return (false);
	if (!_check_cols(map, col))
		return (false);
	return (true);
}

bool	_check_rows(char **map, int row)
{
	int	i;

	i = row;
	while (i >= 0)
	{
		printf("map[%d][row] = %c\n", i, map[i][row]);
		if (map[i][row] == '1')
			return (true);
		if (map[i][row] != ' ' && map[i][row] != '0' && map[i][row] != 'N'
			&& map[i][row] != 'S' && map[i][row] != 'E' && map[i][row] != 'W')
			return (false);
		i--;
	}
	i = row;
	while (map[i])
	{
		printf("map[%d][row] = %c\n", i, map[i][row]);
		if (map[i][row] == '1')
			return (true);
		if (map[i][row] != ' ' && map[i][row] != '0' && map[i][row] != 'N'
			&& map[i][row] != 'S' && map[i][row] != 'E' && map[i][row] != 'W')
			return (false);
		i++;
	}
	return (false);
}

bool	_check_cols(char **map, int col)
{
	int	i;

	i = col;
	if (!map[i])
		return (false);
	while (i >= 0)
	{
		printf("map[col][%d] = %c\n", i, map[col][i]);
		if (map[i][col] == '1')
			return (true);
		if (map[i][col] != ' ' && map[i][col] != '0' && map[i][col] != 'N'
			&& map[i][col] != 'S' && map[i][col] != 'E' && map[i][col] != 'W')
			return (false);
		i--;
	}
	i = col;
	while (map[i])
	{
		printf("map[col][%d] = %c\n", i, map[col][i]);
		if (map[i][col] == '1')
			return (true);
		if (map[i][col] != ' ' && map[i][col] != '0' && map[i][col] != 'N'
			&& map[i][col] != 'S' && map[i][col] != 'E' && map[i][col] != 'W')
			return (false);
		i++;
	}
	return (false);
}

bool	_check_top_bot(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		printf("line[%d] = %c\n", i, line[i]);
		if (line[i] == '\n')
			return (true);
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	_get_in_map(t_game *game, int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (game->data.map[i])
    {
        j = 0;
        while (game->data.map[i][j])
        {
            if (game->data.map[i][j] == '0')
            {
                *row = i;
                *col = j;
                return;
            }
            j++;
        }
        i++;
    }
    *row = -1;
    *col = -1;
}




