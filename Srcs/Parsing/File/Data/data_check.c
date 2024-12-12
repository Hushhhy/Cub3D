/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:08 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/12 14:27:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int  _parse_color_val(char *line, int *i, t_game *game)
{
    int val;

    while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
        (*i)++;
    if (!ft_isdigit(line[*i]))
        _error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
    val = 0;
    while (line[*i] && ft_isdigit(line[*i]))
    {
        val = val * 10 + (line[*i] - '0');
        (*i)++;
    }
    if (val < 0 || val > 255)
        _error_msg_free("Error", ERR_COLOR_RANGE, 1, game);
    while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
        (*i)++;
    if (line[*i] == ',')
    (*i)++;
    return (val);
}

void	_get_ceiling(char *color, t_game *game)
{
	int r;
    int g;
    int b;
    int i;

    _coma_check(color, game);
    i = 1;
    r = _parse_color_val(color, &i, game);
    g = _parse_color_val(color, &i, game);
    b = _parse_color_val(color, &i, game);
    if (color[i] != '\n' && color[i] != '\0')
        _error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
    game->data.ceiling_rgb = (r << 16) + (g << 8) + b;
}

void	_get_floor(char *color, t_game *game)
{
	int r;
    int g;
    int b;
    int i;

    i = 0;
    _coma_check(color, game);
    i = 1;
    r = _parse_color_val(color, &i, game);
    g = _parse_color_val(color, &i, game);
    b = _parse_color_val(color, &i, game);
    if (color[i] != '\n' && color[i] != '\0')
        _error_msg_free("Error", ERR_COLOR_FORMAT, 1, game);
    game->data.floor_rgb = (r << 16) + (g << 8) + b;
}

void    _coma_check(char *color, t_game *game)
{
    int coma;
    int i;

    coma = 0;
    i = 0;
    while (color[i])
    {
        if (color[i] == ',')
            coma++;
        i++;
    }
    if (coma != 2)
        _error_msg_free("Error", ERR_COMA, 1, game);
}
