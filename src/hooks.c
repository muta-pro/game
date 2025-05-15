/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:34:42 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/10 18:06:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

static void	key_event(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (0, mlx_close_window(game->mlx));
	if (!game->game_over)
		handle_input(keydata, game);
}

static void	window_closing(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

void	setup_event_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, &key_event, game);
	mlx_close_hook(game->mlx, &window_closing, game);
}
