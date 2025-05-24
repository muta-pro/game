/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:17:24 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/20 22:47:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	i = 0;
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
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height && grid[i])
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	free(grid);
}

void	print_grid_test(t_map *map)
{
	int	y;

	if (!map || !map->grid)
		ft_printf("is NULL\n");
	if (map->height <= 0)
		ft_printf("map h is 0\n");
	ft_printf("MAP GRID\n");
	ft_printf("dimensions %d, %d)\n", map->width, map->height);
	ft_printf("collect; %d\n,", map->collectibles);
	ft_printf("exits %d\n", map->num_exit);
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y])
			ft_printf("%s\n", map->grid[y]);
		else
			ft_printf("row id %d is NULL\n", y);
		y++;
	}
	ft_printf("..end\n");
}
