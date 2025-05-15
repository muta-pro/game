/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:23:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/10 23:22:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	try_move(t_game *game, int dx, int dy)
{
	int			target_x;
	int			target_y;
	uint32_t	i;

	target_x = game->player.pos.x + dx;
	target_y = game->player.pos.y + dy;
	if (target_x < 0 || target_x >= game->map.width
		|| target_y < 0 || target_y >= game->map.height)
		return ;
	if (game->map.grid[target_y][target_x] == WALL)
		return ;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	moves_show(game);
	game->player.pos.x = target_x;
	game->player.pos.y = target_y;
	game->assets.player_img->instances[0].x = target_x * TILE_SIZE;
	game->assets.player_img->instances[0].y = target_y * TILE_SIZE;
	game->assets.player_img->instances[0].z = 10;
	if (game->map.grid[target_y][target_x] == COLLECTIBLE)
	{
		game->player.collected++;
		game->map.grid[target_y][target_x] = VOID;
	}
	while (i < game->assets.collect_img->count)
	{
		if (game->assets.collect_img->instances[i].enabled) &&
			game->assets.collect_img->instances[i].x == target_x * TILE_SIZE
		&&
	}
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
