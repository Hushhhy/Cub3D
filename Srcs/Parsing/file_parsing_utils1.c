/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:59:33 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/06 13:15:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_emptylines(t_game *game, int start)
{
	int	lc;
	int	i;

	lc = start + 1;
	while (game->data.file[lc])
	{
		i = 0;
		while (game->data.file[lc][i] && (game->data.file[lc][i] == ' '
			|| game->data.file[lc][i] == '\t'
			|| (game->data.file[lc][i] == '\n')))
			i++;
		if (game->data.file[lc][i] != '\0' && game->data.file[lc][i] != '1')
		{
			ft_putstr_fd("Error\nInvalid file format\n", 2);
			exit(1);
		}
		else if (game->data.file[lc][i] == '1')
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
			ft_putstr_fd("Error\nCharacter after map\n", 2);
			exit(1);
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