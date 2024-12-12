/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:10:40 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/12 14:52:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_getmap(t_game *game, int i)
{
	int		start;
	int		k;
	char	*line;
	int		size;

	k = 0;
	start = _emptylines(game, i);
	size = _get_map_size(game, start);
	game->data.map = malloc(sizeof(char *) * (size + 1));
	if (!game->data.map)
		return ;
	while (game->data.file[start])
	{
		line = game->data.file[start];
		if (_line_empty(line))
			break ;
		game->data.map[k] = ft_strdup(line);
		if (!game->data.map[k])
			return ;
		start++;
		k++;
	}
	game->data.map[k] = NULL;
	_check_the_map(game);
}

int	_get_map_size(t_game *game, int i)
{
	int		size;
	int		start;
	char	**file;

	file = game->data.file;
	start = _emptylines(game, i) - 1;
	size = 0;
	while (file[start++])
		if (!_line_empty(file[start]))
			size++;
	return (size);
}
