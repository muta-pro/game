/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:25:20 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/26 00:22:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

static void	put_tile(t_game *game, char tile, int x_pxl, int y_pxl)
{
	mlx_image_t	*put_img;

	put_img = NULL;
	if (tile == WALL)
		put_img = game->assets.wall_img;
	else if (tile == COLLECTIBLE)
		put_img = game->assets.collect_img;
	else if (tile == EXIT_POINT)
		put_img = game->assets.exit_img;
	if (put_img)
	{
		if (mlx_image_to_window(game->mlx, put_img, x_pxl, y_pxl) < 0)
			print_exit(ERR_ASSET_LOAD, game, true);
		else if (tile == EXIT_POINT && put_img->count > 0)
			put_img->instances[put_img->count - 1].z = 1;
		// if (tile == EXIT_POINT && put_img->count > 0)
		// 	put_img->instances[put_img->count - 1].enabled = false;
	}
}

void	render_first_map(t_game *game)
{
	int		x_map_idx;
	int		y_map_idx;
	int		x_pxl;
	int		y_pxl;

	y_map_idx = 0;
	while (y_map_idx < game->map.height)
	{
		x_map_idx = 0;
		while (x_map_idx < game->map.width)
		{
			x_pxl = x_map_idx * TILE_SIZE;
			y_pxl = y_map_idx * TILE_SIZE;
			if (!game->assets.void_img
				|| mlx_image_to_window(game->mlx,
					game->assets.void_img, x_pxl, y_pxl) < 0)
				print_exit("failed to draw empty tile image.", game, true);
			if (game->assets.void_img->count > 0)
				game->assets.void_img
					->instances[game->assets.void_img->count - 1].z = 0;
			put_tile(game, game->map.grid[y_map_idx][x_map_idx], x_pxl, y_pxl);
			++x_map_idx;
		}
		++y_map_idx;
	}
}

void	render_player(t_game *game)
{
	if (game->assets.player_img)
	{
		if (mlx_image_to_window(game->mlx, game->assets.player_img,
				game->player.pos.x * TILE_SIZE,
				game->player.pos.y * TILE_SIZE) < 0)
			print_exit("fail to render player_img", game, true);
		if (game->assets.player_img->count > 0)
		{
			game->player_insta = &game->assets.player_img->instances[0];
			mlx_set_instance_depth(game->player_insta, 10);
		}
	}
	else
		print_exit("player_img is NULL, cannot render", game, true);
}
			// STORE PLAYER INSTANCE SO I CAN  MOVE DIRECTLY

void	moves_display(t_game *game)
{
	char	*moves_str;
	char	*full_str;

	if (game->ui.moves_txt_img != NULL)
	{
		mlx_delete_image(game->mlx, game->ui.moves_txt_img);
		game->ui.moves_txt_img = NULL;
	}
	moves_str = ft_itoa(game->player.moves);
	if (!moves_str)
		print_exit(ERR_MEMORY, game, true);
	full_str = ft_strjoin("MOVES -> ", moves_str);
	free(moves_str);
	if (!full_str)
		print_exit(ERR_MEMORY, game, true);
	game->ui.moves_txt_img = mlx_put_string(game->mlx, full_str, 3, 5);
	free(full_str);
	if (!game->ui.moves_txt_img)
		ft_putstr_fd("could not display move count text\n", STDERR_FILENO);
	ft_printf("Moves: %d\n", game->player.moves);
}
