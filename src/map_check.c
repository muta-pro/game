/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:42:34 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/08 21:41:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

bool	is_rect(t_map *map)
{
	size_t	width;
	int		i;

	width = ft_strlen(map->grid[0]);
	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != width)
			return (false);
		i++;
	}
	return (true);
}

bool	is_closed(t_map *map)
{
	int	x;
	int	y;

	while (map->grid[map->height])
		map->height++;
	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			return (false);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	map_elements(t_map *map)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	map->player = 0;
	map->exit = 0;
	map->collectibles = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			tile = map->grid[y][x];
			if (tile == 'P')
			{
				map->player++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (tile == 'E')
			{
				map->exit++;
				map->exit_x = x;
				map->exit_y = y;
			}
			else if (tile == 'C')
				map->collectibles++;
			else if (tile != '1' && tile != '0')
				return (false);
			x++;
		}
		y++;
	}
	return (map->player == 1 && map->exit == 1 && map->collectibles >= 1);
}

bool	flood_fill_valid_path(char **map, int x, int y)
{
	
}

bool	is_valid(t_map *map)
{
	if (!is_rect(map))
		return (false);
	if (!is_closed(map))
		return (false);
	if (!map_elements(map))
		return (false);
	if (map->player != 1 || map->collectibles < 1 || map->exit != 1)
		return (false);
	if (!check_path(map))
		return (false);
	return (true);
}

int	check_path(t_map *map)
{
	char	**store_map;
	int		collectibles;
	int		exit;
	int		i;

	i = 0;
	store_map = copy_map(map);
	if (!store_map)
		return (0);
	collectibles = map->collectibles;
	exit = 0;
	flood_fill_valid_path(store_map, map->player_x, map->player_y,
		&collectibles, &exit);
	while (i < map->height)
	{
		free(store_map[i]);
		free(store_map);
		i++;
	}
	return (collectibles == 0 && exit == 1);
}
