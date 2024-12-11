/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:51 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 16:20:10 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------INCLUDES-------------------------------*/

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

/*--------------------------ERROR DEF-------------------------------*/



/*------------------------MAIN FUNCTIONS----------------------------*/

int		main(int ac, char **av, char **env);

/*-----------------------------INIT---------------------------------*/

void	_data_init(t_game *game);
void	_player_init(t_game *game);
void	_ray_init(t_game *game);
void	_mlx_init(t_game *game);

/*----------------------------PARSING-------------------------------*/

/*---------------------------------*/
/*--NAME--*/

void	_checkname(char *name);

/*---------------------------------*/
/*--ENV--*/

int		_envcheck(char **env);

/*---------------------------------*/
/*--GET FILE--*/

int     _getfile(t_game *game, char *file);
char	**_gnl_in_file(t_game *game, int lc);
char	*_new_alloc(int start, char *line);

/*---------------------------------*/
/*--FILE PARSING--*/

void	_parse_file(t_game *game);
int	    _get_size(t_game *game);
void	_char_check(char *line);
void	_emptyfile(t_game *game);

/*---------------------------------*/
/*--TEXTURES && COLORS--*/

void	_north_check(t_game *game, char *line);
void	_south_check(t_game *game, char *line);
void	_east_check(t_game *game, char *line);
void	_west_check(t_game *game, char *line);
void	_ceiling_check(t_game *game, char *line);
void	_floor_check(t_game *game, char *line);

/*---------------------------------*/
/*--GET MAP--*/

void	_getmap(t_game *game, int i);
void	_verify(t_game *game, int start);
int	    _is_invalid(char *line, t_game *game);
void	_after_map(t_game *game, int last);
int	    _emptylines(t_game *game, int start);
int	    _line_empty(char *line);
int	    _get_map_size(t_game *game, int i);

/*---------------------------------*/
/*--MAP PARSING--*/

void    _check_the_map(t_game *game);
bool    _check_nb_player(char **map);
bool	_there_is_walls(char **map, int row, int col);
bool	_check_closed_map(t_game *game);
bool	_check_cols(char **map, int y, int x);
bool	_check_rows(char **map, int y, int x);
bool	_check_space_row(char **map, int y, int x);
bool	_check_space_col(char **map, int y, int x);
bool	_check_spaces(char **map, int y, int x);
bool	_check_left(char **map, int y, int i);
bool	_check_right(char **map, int y, int i);
bool	_check_up(char **map, int i, int x);
bool	_check_down(char **map, int i, int x);
bool	_check_top_bot(char *line);
void	_get_ceiling(char *color, t_game *game);
int     _get_map_width(char **map);
int     _get_map_height(char **map);


#endif
