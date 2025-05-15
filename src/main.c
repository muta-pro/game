/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:54:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/11 13:27:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

bool	load_game(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error();
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_struct(&game); //struct initialized
	if (argc != 2)
		print_exit(ERR_ARGS, &game); //partial cleanup
	if (!ber_file(argv[1], ".ber"))
		print_exit(ERR_MAP_EXTENTION, &game);
	load_map(argv[1], &game.map, &game);
	if (!open_window(&game))
		print_exit(ERR_MLX, &game);
	load_player(&game);
	load_graphics(&game);
	event_handler_setup(&game);
	mlx_main(game.mlx);
	final_cleanup(&game);
	return (EXIT_SUCCESS);
}
