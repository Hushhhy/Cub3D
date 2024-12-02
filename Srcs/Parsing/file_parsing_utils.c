/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:24 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/02 16:31:32 by acarpent         ###   ########.fr       */
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
			game->data.floor_color = _new_alloc(i, line);
		while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		{
			game->data.floor_color[j] = line[i];
			j++;
			i++;
		}
        game->data.floor_color[j] = '\0';
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
			game->data.ceiling_color = _new_alloc(i, line);
		while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		{
			game->data.ceiling_color[j] = line[i];
			j++;
			i++;
		}
        game->data.ceiling_color[j] = '\0';
	}
}

// void	_early_map(t_game *game, char *line)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
// 		i++;
// 	if (!ft_strcmp(line, "1"))
// 	{
// 		while (line[i] && !ft_strcmp(line[i], "1"))
// 	}
// }