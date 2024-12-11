/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:22:27 by acarpent          #+#    #+#             */
/*   Updated: 2024/12/11 13:01:20 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_envcheck(char **env)
{
	if (!env)
		return (ft_putstr_fd("Error\nNo environment\n", 2), 1);
	return (0);
}
