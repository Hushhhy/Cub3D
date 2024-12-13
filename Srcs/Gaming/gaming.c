/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:13:33 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/13 15:32:16 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ADD Key to move and exit game
// CF mon so_long

int	_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W || key == KEY_UP)
		move_up(game);
	if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	return (0);
}

void	_gaming(t_game *game)
{
	mlx_loop_hook(game->mlx.mlx_ptr, _raycast, game);
	mlx_hook(game->mlx.mlx_ptr, 2, 1L << 0, _key_press, game);
	mlx_hook(game->mlx.mlx_ptr, 3, 1L << 1, _key_release, game);
	mlx_hook(game->mlx.mlx_ptr, 17, 1L << 17, _close_game, game);
	mlx_loop(game->mlx.mlx_ptr);
}