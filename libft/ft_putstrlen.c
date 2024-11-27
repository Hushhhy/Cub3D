/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:47:04 by acarpent          #+#    #+#             */
/*   Updated: 2024/07/10 14:30:36 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstrlen("(null)"));
	while (s[i])
	{
		ft_putcharlen(s[i]);
		i++;
	}
	return (i);
}
