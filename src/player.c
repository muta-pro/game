/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:23:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/24 23:51:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

static void	exit_game(t_game *game, int y_tile, int x_tile)
{
	if (game->map.grid[y_tile][x_tile] == EXIT_POINT)
	{
		if (game->player.collected_count == game->map.collectibles)
		{
			game->game_over = true;
			mlx_close_window(game->mlx);
		}
		else
			ft_printf("BRO, you can't be saved yet! Collect all the TWIX!\n");
	}
}

static void	when_collected(t_game *game, int y_tile, int x_tile)
{
	if (game->map.grid[y_tile][x_tile] == COLLECTIBLE)
	{
		game->player.collected_count++;
		game->map.grid[y_tile][x_tile] = VOID;
		hide_collected(game, x_tile, y_tile);
	}
}

void	try_move(t_game *game, int dx, int dy)
{
	int			target_x;
	int			target_y;

	if (game->game_over)
		return ;
	target_x = game->player.pos.x + dx;
	target_y = game->player.pos.y + dy;
	if (target_x < 0 || target_x >= game->map.width
		|| target_y < 0 || target_y >= game->map.height)
		return ;
	if (game->map.grid[target_y][target_x] == WALL)
		return ;
	game->player.moves++;
	moves_display(game);
	game->player.pos.x = target_x;
	game->player.pos.y = target_y;
	if (game->player_insta)
	{
		game->player_insta->x = target_x * TILE_SIZE;
		game->player_insta->y = target_y * TILE_SIZE;
	}
	else
		ft_printf("Warning/Error: game->player_insta is NULL in try_move!\n");
	when_collected(game, target_y, target_x);
	exit_game(game, target_y, target_x);
}

void	handle_player(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			try_move(game, 0, -1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			try_move(game, 0, 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			try_move(game, -1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			try_move(game, 1, 0);
	}
}
