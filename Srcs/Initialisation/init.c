/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:38 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 15:25:22 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_data_init(t_game *game)
{
	game->data.file = NULL;
	game->data.fd = -1;
	game->data.no_texture = NULL;
	game->data.so_texture = NULL;
	game->data.we_texture = NULL;
	game->data.ea_texture = NULL;
	game->data.floor_color = NULL;
	game->data.ceiling_color = NULL;
	game->data.f_red = -1;
	game->data.f_green = -1;
	game->data.f_blue = -1;
	game->data.c_red = -1;
	game->data.c_green = -1;
	game->data.c_blue = -1;
	game->data.map = NULL;
	game->data.map_width = -1;
	game->data.map_height = -1;
	_player_init(game);
}

void	_player_init(t_game *game)
{
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	game->player.dir_x = -1;
	game->player.dir_y = -1;
	game->player.plane_x = -1;
	game->player.plane_y = -1;
	_ray_init(game);
}

void	_ray_init(t_game *game)
{
	game->ray.pos_x = -1;
	game->ray.pos_y = -1;
	game->ray.dir_x = -1;
	game->ray.dir_y = -1;
	game->ray.side_dist_x = -1;
	game->ray.side_dist_y = -1;
	game->ray.delta_dist_x = -1;
	game->ray.delta_dist_y = -1;
	game->ray.step_x = -1;
	game->ray.step_y = -1;
	game->ray.hit = -1;
	game->ray.side = -1;
	_mlx_init(game);
}

void	_mlx_init(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
	game->mlx.img_ptr = NULL;
	game->mlx.img_data = NULL;
	game->mlx.bpp = -1;
	game->mlx.size_line = -1;
	game->mlx.endian = -1;
}
