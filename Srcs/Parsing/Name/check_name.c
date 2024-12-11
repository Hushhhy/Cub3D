/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:26 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 13:00:42 by acarpent         ###   ########.fr       */
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
