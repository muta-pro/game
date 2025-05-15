/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:34:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/10 06:07:10 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

static void error_init(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

bool	init_window(t_game *game)
{
	int	window_w;
	int	window_h;

	if (game->map.width <= 0 || game->map.height <= 0)
		return (false);
	window_w = game->map.width * TILE_SIZE;
	window_h = game->map.height * TILE_SIZE;
	mlx_set_settings(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(window_w, window_h, "so_long", false);
	if (!game->mlx)
		return (false);
	return (true);
}

static mlx_image_t	*load_image(mlx_t *mlx, const char *png_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png("./assets/moon.png");
	if (!texture)
		error_init();
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
		error_init();
	return (NULL);
}

int32_t	load_assets(void)
{
	game->assets.wall_img = NULL;
	game->assets.void_img = NULL;
	game->assets.collect_img = NULL;
	game->assets.player_img = NULL;
	game->assets.exit_img = NULL;
	game->assets.wall_img = load_image(game->mlx, "./assets/wall.png");
	if (!game->assets.wall_img)
		return (false);
	game->assets.void_img = load_image(game->mlx, "./assets/void.png");
	if (!game->assets.void_img)
		return (false);
	game->assets.collect_img = load_image(game->mlx, "./assets/collect.png");
	if (!game->assets.collect_img)
		return (false);
	game->assets.player_img = load_image(game->mlx, "./assets/player.png");
	if (!game->assets.player_img)
		return (false);
	game->assets.exit_img = load_image(game->mlx, "./assets/exit");
	if (!game->assets.exit_img)
		return (false);
	return (true);

	mlx_loop_hook(mlx, ft_hook, mlx);//for move counter
	mlx_loop(mlx);
	mlx_key_hook(mlx, mlx_close_esc(), par);
	mlx_close_hook(mlx, mlx_close_x(), par);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
