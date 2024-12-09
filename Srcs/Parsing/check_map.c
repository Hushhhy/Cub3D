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
		ft_putstr_fd("No map\n", 2);
		exit(1);
	}
	if (!_check_map_sides(game, game->data.map))
	{
		ft_putstr_fd("Side\n", 2);
		exit(1);
	}
	if (_get_map_height(game->data.map) < 3)
	{
		ft_putstr_fd("too small\n", 2);
		exit(1);
	}
	if (!_check_nb_player(game->data.map))
	{
		ft_putstr_fd("too many player\n", 2);
		exit(1);
	}
	if (!_check_player_pos(game->data.map))
	{
		ft_putstr_fd("Wrong pos\n", 2);
		exit(1);
	}
}

bool	_check_map_sides(t_game *game, char **map)
{
	int	i;
	int	j;

	if (!_check_bot_top(map, 0, 0))
		return (false);
	i = 1;
	while (i < (game->data.map - 1))
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (false);
		i++;
	}
	if (!check_bot_top(map, i, 0))
		return (false);
}

bool	_check_bot_top(char **map, int i, int j)
{
	if (!map || !map[i] || !map[i][j])
		return (false);
	while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}


