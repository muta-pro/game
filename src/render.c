/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:25:20 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/10 16:38:29 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	render_first_layer(t_game *game)
{
	int	x_map;
	int	y_map;
	int	x_pxl;
	int	y_pxl;

	y_map = 0;
	while (y_map < game->map.height)
	{
		x_map = 0;
		while (x_map < game->map.width)
		{
			x_pxl = x_map * TILE_SIZE;
			y_pxl = x_map * TILE_SIZE;
			if (game->assets.void_img)
			{
				if (mlx_image_to_window(game->mlx, game->assets.void_img,
						x_pxl, y_pxl) < 0)
					print_error("failed to draw empty tile image.", game);
			}
			if (game->map.grid[y_map][x_map] == WALL)
			{
				if (mlx_image_to_window(game->mlx, game->assets.wall_img,
						x_pxl, y_pxl) < 0)
					print_error("failed to draw wall image", game);
			}
			else if (game->map.grid[y_map][x_map] == COLLECTIBLE)
			{
				if (mlx_image_to_window(game->mlx, game->assets.collect_img,
						x_pxl, y_pxl) < 0)
					print_error("failed to draw collectible image", game);
			} //STORE THR INSTANCE ID OR POINTER TO SPEC COLLECTIBLE IMG, to hide easier later
			else if (game->map.grid[y_map][x_map] == EXXIT)
			{
				if (mlx_image_to_window(game->mlx, game->assets.exit_img,
						x_pxl, y_pxl) < 0)
					print_error("failed to draw exit image", game);
			}
			++x;
		}
		++y;
	}
	if (game.assets.player_img)
	{
		if (mlx_image_to_window(game->mlx, game->assets.player_img,
				game->player_x * TILE_SIZE, game->player_y * TILE_SIZE) < 0)
			print_error("failed to draw player image", game);
			//STORE PLAYER INSTANCE SO I CAN  MOVE DIRECTLY
			// game->player.image_instance = &game->assets.player_img
			// ->instances[game->assets.player_img->count - 1];
			//or
			// game->assets.player_img->instances[0].enabled = true;
			// game->assets.player_img->instances[0].z = 10; //player on top
	}
	char	*moves_str;
	char	*full_str;

	moves_str = ft_itoa(game->player.moves);
	if (!moves_str)
		print_error(ERR_MEMORY, game);
	full_str = ft_strjoin("MOVES -> ", moves_str);
	if (!full_str)
	{
		free(moves_str);
		print_error(ERR_MEMORY, game);
	}
	game->ui.moves_text_img = mlx_put_string(game->mlx, full_str, 5, 5);
	if (!game->ui.moves_text_img)
		ft_putstr_fd("could not display move count text\n", STDERR_FILENO);
	free(moves_str);
	free(full_str);
}
