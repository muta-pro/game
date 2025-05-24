/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:34:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/24 11:57:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

// static void	error_init(void)
// {
// 	ft_printf("%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

bool	init_mlx_window(t_game *game)
{
	int		window_w;
	int		window_h;

	window_w = game->map.width * TILE_SIZE;
	window_h = game->map.height * TILE_SIZE;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(window_w, window_h, WINDOW_TITLE, true);
	if (!game->mlx)
		print_exit(ERR_MLX, game, true);
	return (true);
}

mlx_image_t	*load_image(mlx_t *mlx, const char *png_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(png_path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (NULL);
	return (image);
}

static void	set_null_asset(t_game *game)
{
	game->assets.wall_img = NULL;
	game->assets.void_img = NULL;
	game->assets.collect_img = NULL;
	game->assets.player_img = NULL;
	game->assets.exit_img = NULL;
	// game->assets.enemies_img = NULL;
}

bool	load_graphics(t_game *game)
{
	set_null_asset(game);
	game->assets.wall_img = load_image(game->mlx, "./assets/wall.png");
	if (!game->assets.wall_img)
		print_exit(ERR_ASSET_LOAD, game, true);
	game->assets.void_img = load_image(game->mlx, "./assets/void.png");
	if (!game->assets.void_img)
		print_exit(ERR_ASSET_LOAD, game, true);
	game->assets.collect_img = load_image(game->mlx, "./assets/collect.png");
	if (!game->assets.collect_img)
		print_exit(ERR_ASSET_LOAD, game, true);
	game->assets.player_img = load_image(game->mlx, "./assets/player.png");
	if (!game->assets.player_img)
		print_exit(ERR_ASSET_LOAD, game, true);
	game->assets.exit_img = load_image(game->mlx, "./assets/exit.png");
	if (!game->assets.exit_img)
		print_exit(ERR_ASSET_LOAD, game, true);
	// game->assets.enemies_img = load_image(game->mlx, "./assets/enemy.png");
	// if (!game->assets.enemies_img)
	// 	print_exit(ERR_ASSET_LOAD, game, true);
	return (true);
}
