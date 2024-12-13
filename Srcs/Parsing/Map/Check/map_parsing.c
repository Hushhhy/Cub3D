/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:04:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 15:04:12 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_check_the_map(t_game *game)
{
	if (!game->data.map)
		exit(_error_msg_free("Detail", ERR_NO_MAP, 1, game));
	if (_get_map_height(game->data.map) < 3)
		exit(_error_msg_free("Detail", ERR_SMALL_MAP, 1, game));
	if (!_check_nb_player(game->data.map, game))
		exit(_error_msg_free("Detail", ERR_PLAYER, 1, game));
	if (!_check_closed_map(game))
		exit(_error_msg_free("Detail", ERR_CLOSED, 1, game));
}

bool	_check_nb_player(char **map, t_game *game)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'O' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (flag == true)
					return (false);
				_player_pos(game, i, j);
				flag = true;
			}
			j++;
		}
		i++;
	}
	return (true);
}

void	_player_pos(t_game *game, int i, int j)
{
	game->player.pos_x = j;
	game->player.pos_y = i;
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
