/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:25:21 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/06 18:39:43 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <MLX42.h>
#include "geme.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			x;

	x = 0;
	mlx = mlx_init(800, 400, "TITLE", true);
	image = mlx_new_image(mlx, 64, 64);
	while (x <= 52)
	{
		mlx_put_pixel(image, x, 32, 0xFFFFFFFF);
		x++;
	}
	mlx_image_to_window(mlx, image, 32, 32);//position of the image related to window
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
