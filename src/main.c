/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:54:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/24 14:16:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	print_grid_test(t_map *map);

static void	init_g_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->game_over = false;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		print_exit(ERR_ARGS, NULL, false);
	init_g_struct(&game);
	if (!load_map(&game, argv[1]))
		return (EXIT_FAILURE);
	print_grid_test(&game.map);
	if (!init_mlx_window(&game))
		print_exit(ERR_MLX, &game, true);
	if (!load_graphics(&game))
		print_exit(ERR_ASSET_LOAD, &game, true);
	render_first_map(&game);
	render_player(&game);
	moves_display(&game);
	setup_event_hooks(&game);
	mlx_loop(game.mlx);
	final_cleanup(&game);
	return (EXIT_SUCCESS);
}

// void event_handler_setup(t_game *game)
// {
// 	mlx_loop_hook(game->mlx, ft_hook, mlx);//for move counter
// 	mlx_key_hook(mlx, mlx_close_esc(), par);
// 	mlx_close_hook(mlx, mlx_close_x(), par);
// 	mlx_delete_image(mlx, image);
// 	mlx_terminate(mlx);
// }