/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:18:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/24 22:53:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"
/*
check for .ber extention
prepend/maps/ to the name and return full path
open file
use gnl ro reade line by line
concatenate each line to 
or NULL
*/

static char	*read_map_lines(int fd, t_game *game)
{
	char	*line;
	char	*full_str;
	char	*store;

	full_str = ft_strdup("");
	if (!full_str)
		print_exit(ERR_MEMORY, game, false);
	line = get_next_line(fd);
	if (!line && ft_strlen(full_str) == 0)
	{
		free(full_str);
		print_exit(ERR_MAP_EMPTY, game, false);
	}
	while (line != NULL)
	{
		store = ft_strjoin(full_str, line);
		free(full_str);
		free(line);
		if (!store)
			print_exit(ERR_MEMORY, game, false);
		full_str = store;
		line = get_next_line(fd);
	}
	return (full_str);
}

char	**str_to_grid(int fd, int *height, t_game *game)
{
	char	*found_str;
	char	**grid;

	found_str = read_map_lines(fd, game);
	if (ft_strnstr(found_str, "\n\n", ft_strlen(found_str)))
	{
		free(found_str);
		print_exit(ERR_MAP_CHARS, game, false);
	}
	grid = ft_split(found_str, '\n');
	free(found_str);
	if (!grid)
		print_exit(ERR_MEMORY, game, false);
	*height = 0;
	while (grid[*height])
		(*height)++;
	if (*height == 0)
	{
		free_grid(grid, 0);
		print_exit(ERR_MAP_EMPTY, game, false);
	}
	return (grid);
}

char	*find_map(const char *map_name)
{
	char	*dot;
	char	*holder;

	dot = ft_strrchr(map_name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5))
		return (NULL);
	holder = ft_strjoin("maps/", map_name);
	if (!holder)
		return (NULL);
	return (holder);
}

static int	open_map(const char *name, t_game *game)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		print_exit(ERR_MAP_OPEN, game, false);
	return (fd);
}

bool	load_map(t_game *game, const char *filename)
{
	int		fd;
	char	*map_path;

	map_path = find_map(filename);
	if (!map_path)
		print_exit(ERR_MAP_EXTENTION, game, false);
	fd = open_map(map_path, game);
	free(map_path);
	game->map.grid = str_to_grid(fd, &game->map.height, game);
	close(fd);
	if (!game->map.grid)
		return (false);
	if (!parse_valid_map(game))
		return (false);
	game->player.pos = game->map.player_pos;
	game->player.moves = 0;
	game->player.collected_count = 0;
	return (true);
}
