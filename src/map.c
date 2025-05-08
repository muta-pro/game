/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:18:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/08 21:41:20 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"
/*
check for .ber extention
prepend/maps/ to the name and return full path
open file
use gnl ro reade line by line
concatenate each line to 
or NULL
*/

char	*add_line(char **map, char **line)
{
	char	*holder;

	if (!*map)
		*map = ft_strdup("");
	if (!*map || !*line)
		return (NULL);
	holder = ft_strjoin(*map, *line);
	free(*map);
	free(*line);
	*map = NULL;
	*line = NULL;
	return (holder);
}

char	*find_map(char *map_name)
{
	char	*dot;
	char	*holder;

	dot = ft_strrchr(map_name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5))
		return (NULL);
	holder = ft_strjoin("maps/", map_name);
	if (!holder)
		return (NULL);
	return (holder);
}

char	*get_map(char *name)
{
	int		fd;
	char	*read;
	char	*mapping;

	mapping = find_map(name);
	if (!mapping)
	{
		printf("error: invalid name\n");
		return (NULL);
	}
	fd = open(mapping, O_RDONLY);
	free(mapping);
	if (fd == -1)
	{
		printf("error opening map\n");
		return (NULL);
	}
	mapping = NULL;
	while (true)
	{
		read = get_next_line(fd);
		if (read == NULL)
			break ;
		mapping = add_line(&mapping, &read);
	}
	close(fd);
	if (!mapping)
		printf("error empty map\n");
	printf("done!\n");
	return (mapping);
}
