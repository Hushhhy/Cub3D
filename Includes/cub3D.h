/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:51 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/12 14:21:21 by codespace        ###   ########.fr       */
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

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/*----------------------------COLORS--------------------------------*/

# define RED "\e[31m"
# define RESET	"\e[0m"

/*--------------------------ERROR DEF-------------------------------*/

# define ERR_ARG "./cub3d <path/to/map.cub>"
# define ERR_NAME "Has to be a .cub file"
# define ERR_IS_DIR "Is a directory"
# define ERR_ENV "Environment not found"
# define ERR_GET_FILE "File doesn't exist"
# define ERR_EMPTY "Empty file"
# define ERR_CHAR "Invalid character in map"
# define ERR_NORTH "Too many north textures"
# define ERR_SOUTH "Too many south textures"
# define ERR_EAST "Too many east textures"
# define ERR_WEST "Too many west textures"
# define ERR_FLOOR "Too many floor colors"
# define ERR_CEILING "Too many ceiling colors"
# define ERR_FORMAT "Invalid map format"
# define ERR_AFTER "Invalid characters after map"
# define ERR_NO_MAP "No map found"
# define ERR_SMALL_MAP "Map too small"
# define ERR_PLAYER "Invalid number of players"
# define ERR_CLOSED "Map not closed"
# define ERR_COLOR_FORMAT "Invalid color format"
# define ERR_COLOR_RANGE "Color out of range"
# define ERR_COMA "Coma number must be 2"

/*------------------------MAIN FUNCTIONS----------------------------*/

int		main(int ac, char **av);

/*-----------------------------INIT---------------------------------*/

void	_data_init(t_game *game);
void	_player_init(t_game *game);
void	_ray_init(t_game *game);
void	_mlx_init(t_game *game);

/*----------------------------PARSING-------------------------------*/

/*---------------------------------*/
/*--ERROR--*/

int 	_error_msg_free(char *det, char *str, int code, t_game *game);
int	    _error_msg(char *det, char *str, int code);
int	    _err_msg_val(int detail, char *str, int code, t_game *game);
void    _has_to_free(t_game *game);
void    _free_texture(char *no, char *so, char *ea, char *we);
void    _free_colors(char *ceiling, char *floor);

/*---------------------------------*/
/*--NAME OR DIR--*/

void	_checkname(char *name);
bool	_is_directory(char *name);

/*---------------------------------*/
/*--GET FILE--*/

int     _getfile(t_game *game, char *file);
char	**_gnl_in_file(t_game *game, int lc);
char	*_new_alloc(int start, char *line);

/*---------------------------------*/
/*--FILE PARSING--*/

void	_parse_file(t_game *game);
int	    _get_size(t_game *game);
void	_char_check(char *line, t_game *game);
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

void        _check_the_map(t_game *game);
bool        _check_nb_player(char **map);
bool	    _there_is_walls(char **map, int row, int col);
bool	    _check_closed_map(t_game *game);
bool	    _check_cols(char **map, int y, int x);
bool	    _check_rows(char **map, int y, int x);
bool	    _check_space_row(char **map, int y, int x);
bool	    _check_space_col(char **map, int y, int x);
bool	    _check_spaces(char **map, int y, int x);
bool	    _check_left(char **map, int y, int i);
bool	    _check_right(char **map, int y, int i);
bool	    _check_up(char **map, int i, int x);
bool	    _check_down(char **map, int i, int x);
bool	    _check_top_bot(char *line);
void	    _get_ceiling(char *color, t_game *game);
void	    _get_floor(char *color, t_game *game);
void        _coma_check(char *color, t_game *game);
int         _get_map_width(char **map);
int         _get_map_height(char **map);


#endif
