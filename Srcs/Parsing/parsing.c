/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:52 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 11:37:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_checkname(char *name)
{
	char	*ext;
	ext = ft_strrchr(name, '.');
	if (!ext || ft_strncmp(ext, ".cub\0", 5))
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		exit(0);
	}
}

int	_envcheck(char **env)
{
	if (!env)
		return (ft_putstr_fd("Error\nNo environment\n", 2), 1);
	return (0);
}


