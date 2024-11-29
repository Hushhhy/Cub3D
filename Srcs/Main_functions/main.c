/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:52:53 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 11:40:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av, char **env)
{
    t_game    game;

    if (ac != 2)
        return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
    _checkname(av[1]);
    _envcheck(env);
    _data_init(&game);
    if (!_getfile(&game, av[1]))
        return (ft_putstr_fd("Error\nfile don't exist\n", 2), 1);
}
