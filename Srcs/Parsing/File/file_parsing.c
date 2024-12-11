/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:56:40 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 13:09:17 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_parse_file(t_game *game)
{
	int	i;

	i = 0;
	_emptyfile(game);
	while (game->data.file[i])
	{
		_char_check(game->data.file[i]);
		_north_check(game, game->data.file[i]);
		_south_check(game, game->data.file[i]);
		_east_check(game, game->data.file[i]);
		_west_check(game, game->data.file[i]);
		_floor_check(game, game->data.file[i]);
		_ceiling_check(game, game->data.file[i]);
		if (game->data.no_texture && game->data.so_texture
			&& game->data.ea_texture && game->data.we_texture
			&& game->data.ceiling_color && game->data.floor_color)
		{
			_verify(game, i);
			_getmap(game, i);
			return ;
		}
		i++;
	}
}

void	_emptyfile(t_game *game)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (game->data.file[i])
	{
		j = 0;
		while ((game->data.file[i][j] == ' ' || game->data.file[i][j] == '\t'
			|| game->data.file[i][j] == '\n') && game->data.file[i][j])
			j++;
		if (!(game->data.file[i][j] == ' ' || game->data.file[i][j] == '\t'
			|| game->data.file[i][j] == '\n') && game->data.file[i][j])
			flag++;
		i++;
	}
	if (flag == 0)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		exit(1);		
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
