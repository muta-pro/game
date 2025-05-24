/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:58:31 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/24 14:33:42 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	hide_collected(t_game *game, int coll_tile_x, int coll_tile_y)
{
	int				target_x;
	int				target_y;
	uint32_t		i;
	mlx_instance_t	*insta;

	target_x = coll_tile_x * TILE_SIZE;
	target_y = coll_tile_y * TILE_SIZE;
	i = 0;
	while (i < game->assets.collect_img->count)
	{
		insta = &game->assets.collect_img->instances[i];
		if (insta->enabled && insta->x == target_x
			&& insta->y == target_y)
		{
			insta->enabled = false;
			break ;
		}
		i++;
	}
}

void	print_exit(const char *errmsg, t_game *game, bool do_cleanup)
{
	if (errmsg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd((char *)errmsg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (do_cleanup && game)
		final_cleanup(game);
	exit(do_cleanup);
}

static void	del_img(t_game *game)
{
	if (game->assets.wall_img)
		mlx_delete_image(game->mlx, game->assets.wall_img);
	if (game->assets.void_img)
		mlx_delete_image(game->mlx, game->assets.void_img);
	if (game->assets.collect_img)
		mlx_delete_image(game->mlx, game->assets.collect_img);
	if (game->assets.player_img)
		mlx_delete_image(game->mlx, game->assets.player_img);
	if (game->assets.exit_img)
		mlx_delete_image(game->mlx, game->assets.exit_img);
	if (game->ui.moves_txt_img)
		mlx_delete_image(game->mlx, game->ui.moves_txt_img);
}

void	final_cleanup(t_game *game)
{
	if (!game)
		return ;
	if (game->map.grid)
	{
		free_grid(game->map.grid, game->map.height);
		game->map.grid = NULL;
	}
	if (game->mlx)
		del_img(game);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
}
