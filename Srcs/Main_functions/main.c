/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:44 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/12 13:33:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (_error_msg("Usage", ERR_ARG, 1));
	_checkname(av[1]);
	_data_init(&game);
	if (!_getfile(&game, av[1]))
		return (_error_msg("Detail", ERR_GET_FILE, 1));
	_parse_file(&game);
}
