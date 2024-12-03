/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:27 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/03 15:20:29 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_checkname(char *name)
{
	char	*ext;

	ext = ft_strrchr(name, '.');
	if (!ext || ft_strncmp(ext, ".cub\0", 5))
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		exit(0);
	}
}

int	_envcheck(char **env)
{
	if (!env)
		return (ft_putstr_fd("Error\nNo environment\n", 2), 1);
	return (0);
}

int	_getfile(t_game *game, char *file)
{
	int		lc;

	lc = 0;
	game->data.fd = open(file, O_RDONLY);
	if (game->data.fd < 0)
		return (0);
	lc = _get_size(game);
	close(game->data.fd);
	game->data.fd = open(file, O_RDONLY);
	game->data.file = _gnl_in_file(game, lc);
	if (!game->data.file)
		return (0);
	close(game->data.fd);
	return (1);
}

int	_get_map_size(t_game *game, int i)
{
	while (game->data.file[i])
		i++;
	return (i);
}

int	_get_map(t_game *game, int start)
{
	int		lc;
	int		map_start;
	char	**file;

	file = game->data.file;
	lc = _get_map_size(game, start);
	game->data.map = malloc((lc + 1) * sizeof(char *));
	if (!game->data.map)
		return (0);
	printf("%s", file[start]);
	map_start = 0;
	while (file[++start])
	{
		game->data.map[map_start] = ft_strdup(file[start]);
		if (!game->data.map[map_start])
			return (0);
		map_start++;
	}
	printf("%s", file[start]);
	game->data.map[map_start] = NULL;
	_parse_map(game);
	return (1);
}
