/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:42:34 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/20 22:52:11 by imutavdz         ###   ########.fr       */
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

static bool	tile_check(t_map *map, char tile, int x, int y)
{
	if (tile == 'P')
	{
		map->player++;
		map->player_pos.x = x;
		map->player_pos.y = y;
	}
	else if (tile == 'E')
	{
		map->num_exit++;
		map->exit_pos.x = x;
		map->exit_pos.y = y;
	}
	else if (tile == 'C')
		map->collectibles++;
	else if (tile != '1' && tile != '0')
		return (false);
	return (true);
}

bool	valid_char(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	map->player = 0;
	map->num_exit = 0;
	map->collectibles = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!tile_check(map, map->grid[y][x], x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	parse_valid_map(t_game *game)
{
	if (!game->map.grid[0] || game->map.height <= 0)
		print_exit(ERR_MAP_EMPTY, game, true);
	game->map.width = ft_strlen(game->map.grid[0]);
	if (game->map.width == 0)
		print_exit(ERR_MAP_EMPTY, game, true);
	if (!is_rect(&game->map))
		print_exit(ERR_MAP_RECT, game, true);
	if (!is_closed(&game->map))
		print_exit(ERR_MAP_WALLS, game, true);
	if (!valid_char(&game->map))
		print_exit(ERR_MAP_CHARS, game, true);
	if (game->map.player != 1)
		print_exit(ERR_MAP_PLAYER, game, true);
	if (game->map.num_exit < 1)
		print_exit(ERR_MAP_EXIT, game, true);
	if (game->map.collectibles < 1)
		print_exit(ERR_MAP_COLLECT, game, true);
	if (!check_path(&game->map))
		print_exit("Error, path invalid", game, true);
	return (true);
}
