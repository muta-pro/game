/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:24:07 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/10 17:46:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define TILE_SIZE 64
# define WINDOW_TITLE "so_long"
# define WIDTH 256
# define HEIGHT 256

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXITE 'E'

//error messages
# define ERR_ARGS "Error\nIncorrect number of arguments"
# define ERR_MAP_CHARS "Error\nInvalid characters in map"
# define ERR_MAP_RECT "Error\nMap is not rectangular"
# define ERR_MAP_WALLS "Error\nMap is not surrounded by walls"
# define ERR_MAP_PLAYER "Error\nMap must have exactly one player"
# define ERR_MAP_EXIT "Error\nMap must have at least one exit"
# define ERR_MAP_COLLECT "Error\nMap must have at least one collectible"
# define ERR_MAP_PATH "Error\nNo valid path to collect all items and reach exit"
# define ERR_MAP_EXTENTION "Error\nMap file must have .ber extension"
# define ERR_MAP_OPEN "Error\nCould not open map file"
# define ERR_MEMORY "Error\nMemory allocation failed"
# define ERR_MLX "Error\nMLX initialization failed"

typedef struct s_position
{
	int x;
	int y;
} t_pos;

typedef struct s_player
{
	t_pos	pos; //curr pos
	int		moves;
	int		collected;
} t_player;

typedef struct s_map
{
	char	**grid; //2D ARRAY
	int		width;
	int		height;
	int		collectibles; //TOT COLLECTIBLES
	int		exit; //NUM OF EXITS
	int 	player; //NUM OF POSITIONS
	t_pos	exit_pos; //EXIT POSITION
	t_pos	player_start; //STARTING POSITION
} t_map;

typedef struct s_assets
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*void_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*wall_img;
	mlx_image_t		*void_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
} t_assets;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map; //map data struct
	t_player	player; //player data
	t_assets	assets; //game assets
	bool		game_over;
} t_game;


	


char	**load_map(const char *file, int *width, int *height);

void	render_map(t_game *game);
void	print_error(char *message);
void	game_loop(t_game *game);

char        *get_map(char *name);
bool        is_valid(char *map);
bool        is_playable(char **map);
void        find_start(int *start_x, int *start_y, char **map);

#endif