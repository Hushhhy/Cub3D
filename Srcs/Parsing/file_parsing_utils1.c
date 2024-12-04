/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:59:33 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/04 15:43:32 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_emptylines(t_game *game, int start)
{
	int	lc;
	int	i;

	lc = start + 1;
	i = 0;
	while (game->data.file[lc])
	{
		while (game->data.file[lc][i] && (game->data.file[lc][i] == ' '
			|| game->data.file[lc][i] == '\t'
			|| (game->data.file[lc][i] == '\n')))
			i++;
		if (game->data.file[lc][i] == '1')
			break ;
		lc++;
	}
	return (lc);
}

int	_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

void	_after_map(t_game *game, int last)
{
	int		i;
	char	*line;

	i = last + 1;
	while (game->data.file[i])
	{
		line = game->data.file[i];
		if (!_line_empty(line))
		{
			ft_putstr_fd("Error\nInvalid file: 10\n", 2);
			exit(1);
		}
		i++;
	}
}