/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:56:40 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/04 15:52:19 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_parse_file(t_game *game)
{
	int	i;

	i = 0;
	while (game->data.file[i])
	{
		_north_check(game, game->data.file[i]);
		_south_check(game, game->data.file[i]);
		_east_check(game, game->data.file[i]);
		_west_check(game, game->data.file[i]);
		_floor_check(game, game->data.file[i]);
		_ceiling_check(game, game->data.file[i]);
		if (!game->data.no_texture || !game->data.so_texture
			|| !game->data.ea_texture || !game->data.we_texture
			|| !game->data.ceiling_color || !game->data.floor_color)
			_char_check(game->data.file[i]);
		else
		{
			_verify(game, i);
			// _getmap(game);
			return ;
		}
		i++;
	}
}

void	_north_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.no_texture)
		{
			game->data.no_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.no_texture[j++] = line[i++];
			game->data.no_texture[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nInvalid file: 1\n", 2);
			exit(1);
		}
	}
}

void	_south_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "SO ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.so_texture)
		{
			game->data.so_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.so_texture[j++] = line[i++];
			game->data.so_texture[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nInvalid file: 2\n", 2);
			exit(1);
		}
	}
}

void	_east_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "EA ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.ea_texture)
		{
			game->data.ea_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.ea_texture[j++] = line[i++];
			game->data.ea_texture[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nInvalid file: 3\n", 2);
			exit(1);
		}
	}
}

void	_west_check(t_game *game, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!ft_strncmp(line, "WE ", 3))
	{
		i += 3;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (!game->data.we_texture)
		{
			game->data.we_texture = _new_alloc(i, line);
			while (line[i] && (line[i] != ' ' && line[i] != '\t'))
				game->data.we_texture[j++] = line[i++];
			game->data.we_texture[j] = '\0';
		}
		else
		{
			ft_putstr_fd("Error\nInvalid file: 4\n", 2);
			exit(1);
		}
	}
}
