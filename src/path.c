/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:31:18 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/20 23:04:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	flood_fill_rec(int x, int y, t_path *data)
{
	if (x < 0 || y < 0 || y >= data->height || x > data->width
		|| data->map_copy[y][x] == '1' || data->map_copy[y][x] == 'X')
		return ;
	if (data->map_copy[y][x] == 'C')
		(*(data->collectibles))--;
	if (data->map_copy[y][x] == 'E')
		*(data->exit_flag) = 1;
	data->map_copy[y][x] = 'X';
	flood_fill_rec(x + 1, y, data);
	flood_fill_rec(x - 1, y, data);
	flood_fill_rec(x, y + 1, data);
	flood_fill_rec(x, y - 1, data);
}

bool	check_path(t_map *map)
{
	t_path	ff_data;
	char	**store_map;
	int		to_collect;
	int		exit;
	int		i;

	i = 0;
	exit = 0;
	store_map = copy_map(map);
	if (!store_map)
		return (false);
	to_collect = map->collectibles;
	ff_data.map_copy = store_map;
	ff_data.collectibles = &to_collect;
	ff_data.width = map->width;
	ff_data.height = map->height;
	ff_data.exit_flag = &exit;
	flood_fill_rec(map->player_pos.x, map->player_pos.y, &ff_data);
	free_grid(ff_data.map_copy, ff_data.height);
	return (to_collect == 0 && exit == 1);
}
