/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:17:24 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/08 21:41:21 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	print_error(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
	}
	copy = NULL;
	return (copy);
}
