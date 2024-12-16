/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:07:23 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/16 13:33:26 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_INIT, 1, game));
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->mlx.win_ptr)
		exit(_error_msg_free("mlx", ERR_MLX_WIN, 1, game));
	return ;
}
