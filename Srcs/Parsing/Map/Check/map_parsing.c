/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:04:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 15:32:21 by acarpent         ###   ########.fr       */
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

bool	_check_nb_player(char **map)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = false;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'O' || map[j][i] == 'N'
				|| map[j][i] == 'E' || map[j][i] == 'S')
			{
				if (flag == true)
					return (false);
				flag = true;
			}
			i++;
		}
		j++;
	}
	return (true);
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
			if (game->data.map[i][j] == '0' || game->data.map[i][j] == 'N'
				|| game->data.map[i][j] == 'S' || game->data.map[i][j] == 'O'
				|| game->data.map[i][j] == 'E')
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
