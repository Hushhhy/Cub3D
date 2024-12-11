/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:03:24 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 13:04:28 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			ft_putstr_fd("Error\nToo many north texture\n", 2);
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
			ft_putstr_fd("Error\nToo many south texture\n", 2);
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
			ft_putstr_fd("Error\nToo many east texture\n", 2);
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
			ft_putstr_fd("Error\nToo many west texture\n", 2);
			exit(1);
		}
	}
}
