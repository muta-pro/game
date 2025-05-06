/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:24:07 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/06 10:19:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <mlx.h>
#include <stdlib.h>
#include <fctnl.h>
#include <unistd.h>

# define TILE_SIZE 64
# define WINDOW_TITLE "solong"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXITE 'E'

