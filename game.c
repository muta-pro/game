/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:44:41 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/06 18:40:11 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int main(int argc, char *argv[])
{
	char *map;

	if (argc != 2)
		return (write(2, "Error\n", 6), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (free(map), write(2, "Error\n", 6), -1);
	game(map);
	free(map);
}
/*
validate map
