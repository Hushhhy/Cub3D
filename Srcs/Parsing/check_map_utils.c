/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:29:50 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/09 13:57:18 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	_check_nb_player(char **map)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = false;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'O' || map[j][i] == 'N'
				|| map[j][i] == 'E' || map[j][i] == 'S')
			{
				if (flag == true)
					return (false);
				flag = true;
			}
			i++;
		}
		j++;
	}
	return (true);
}

int	_get_map_width(char **map)
{
	int		i;
	size_t	width;

	i = 1;
	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > width)
			width = ft_strlen(map[i]);
		i++;
	}
	return (width);
}

int	_get_map_height(char **map)
{
	int i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}
