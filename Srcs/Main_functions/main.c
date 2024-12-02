/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:44 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/02 14:48:24 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av, char **env)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	_checkname(av[1]);
	_envcheck(env);
	_data_init(&game);
	if (!_getfile(&game, av[1]))
		return (ft_putstr_fd("Error\nfile doesn't exist\n", 2), 1);
	_parse_file(&game);
}
