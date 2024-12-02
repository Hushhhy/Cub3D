/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:10:57 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:27 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	_parse_map()
// {
	
// }

int	_get_file_size(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->data.fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(game->data.fd);
	}
	return (i);
}

char	**_gnl_in_file(t_game *game, int lc)
{
	char	**infile;
	char	*line;
	int		i;

	i = 0;
	infile = malloc(sizeof(char *) * (lc + 1));
	if (!infile)
		return (NULL);
	line = get_next_line(game->data.fd);
	while (line)
	{
		infile[i] = line;
		line = get_next_line(game->data.fd);
		i++;
	}
	infile[i] = NULL;
	return (infile);
}

char	*_new_alloc(int start, char *line)
{
	int		i;
	int		end;
	char	*tmp;

	i = start;
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	end = i - start;
	tmp = malloc(sizeof(char) * (end + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}
