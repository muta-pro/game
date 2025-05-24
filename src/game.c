/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:44:41 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/17 17:42:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

// static void info_grid(t_map *m)
// {
// 	int x;
// 	int y;

// 	m->height = 0;
// 	m->width = ft_strlen(m->grid[0]);
// 	m->collectibles = 0;
// 	m->exit = -0
// }

/*
validate map
*/

// void	check_args(int argc, char **argv)
// {
// 	if (argc != 2)
// 		error_exit("Error: Invalid number of arguments", NULL);
// 	validate_file_extension(argv[1]);
// 	check_file_access(argv[1]);
// }

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 		error_exit("Error: Invalid number of arguments", NULL);
// 	validate_file_extension(argv[1]);
// 	check_file_access(argv[1]);
// 	ft_memset(&game, 0, sizeof(t_game));
// 	if (!init_game(&game, argv[1]))
// 	{
// 		cleanup_game(&game);
// 		error_exit("Error: Game initialization failed", NULL);
// 	}
// 	mlx_close_hook(game.mlx, &handle_close, &game);
// 	mlx_loop(game.mlx);
// 	cleanup_game(&game);
// 	return (EXIT_SUCCESS);
// }
