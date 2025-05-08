/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:44:41 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/08 21:41:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	main(int argc, char *argv[])
{
	char	*map_str;
	t_game	game;
	t_map	*map;

	if (argc != 2)
		print_error(ERR_ARGS);
	map_str = get_map(argv[1]);
	if (!map_str)
		print_error(ERR_MAP_OPEN);
	printf("map contents:\n%s", map_str);
	game.map.grid = ft_split(map_str, '\n');
	free(map_str);
	if (!game.map.grid)
		print_error(ERR_MEMORY);
	game->map->height = get_height(game->map->grid);
	game->map->width = ft_strlen(game->map->grid[0]);
	game.map = map_table;
	if (!is_valid(&game.map))
		print_error("invalid map\n");
	init_player_position(&game);
	game_loop(&game);
	return (0);
}
/*
validate map
*/

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		error_exit("Error: Invalid number of arguments", NULL);
	validate_file_extension(argv[1]);
	check_file_access(argv[1]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Error: Invalid number of arguments", NULL);
	validate_file_extension(argv[1]);
	check_file_access(argv[1]);
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game, argv[1]))
	{
		cleanup_game(&game);
		error_exit("Error: Game initialization failed", NULL);
	}
	mlx_close_hook(game.mlx, &handle_close, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (EXIT_SUCCESS);
}
