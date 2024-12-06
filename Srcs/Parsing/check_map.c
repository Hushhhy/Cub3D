/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:04:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/06 15:36:48 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool    _check_nb_player(char **map)
{
    int     i;
    int     j;
    bool    flag;

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

bool    _check_closed_map(char **map, t_game *game)
{
    int i;
    int j;

    i = 0;
    game->data.map_width = _get_map_width(map);
    game->data.map_height = _get_map_height(map);
    while (map[i])
    {
        j = 0;
        while (map[i][j] != game->data.map_width)
        {
            
        }
    }
}

void    _check_the_map(t_game *game)
{
    if (_check_nb_player(game->data.map) == false)
    {
        ft_putstr_fd("Error\nPlayer number must be 1\n", 2);
        exit(1);
    }
    if (_check_closed_map(game->data.map, game) == false)
    {
        ft_putstr_fd("Error\nWrong map format\n", 2);
        exit(1);
    }
}

int _get_map_width(char **map)
{
    int i;
    int width;

    i = 1;
    width = ft_strlen(map[0]);
    while (map[i])
    {
        if (ft_strlen(map[i]) > width)
            width = ft_strlen(map[i]);
        i++;
    }
    return (width);
}

int _get_map_height(char **map)
{
    int i;
    
    i = 0;
    while (map[i])
        i++;
    return (i);
}