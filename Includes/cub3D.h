/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:51 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/03 15:17:23 by acarpent         ###   ########.fr       */
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

/*------------------------MAIN FUNCTIONS----------------------------*/

int		main(int ac, char **av, char **env);

/*-----------------------------INIT---------------------------------*/

void	_data_init(t_game *game);
void	_player_init(t_game *game);
void	_ray_init(t_game *game);
void	_mlx_init(t_game *game);

/*----------------------------PARSING-------------------------------*/

void	_checkname(char *name);
int		_envcheck(char **env);
int     _getfile(t_game *game, char *file);
int	    _get_size(t_game *game);
char	**_gnl_in_file(t_game *game, int lc);
void	_parse_file(t_game *game);
void	_north_check(t_game *game, char *line);
void	_south_check(t_game *game, char *line);
void	_east_check(t_game *game, char *line);
void	_west_check(t_game *game, char *line);
void	_ceiling_check(t_game *game, char *line);
void	_floor_check(t_game *game, char *line);
char	*_new_alloc(int start, char *line);
void	_early_map(char *line);
int 	_get_map(t_game *game, int start);
void	_parse_map(t_game *game);
char	**_skip_this(char **file);

#endif
