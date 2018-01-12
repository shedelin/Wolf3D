/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 19:56:38 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 19:56:39 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "wolf_3D.h"
#include "libft.h"
#include "get_next_line.h"

static void		w3_get_size_map(char *name, t_env *env);

char			**w3_get_map(char *name, t_env *env)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	w3_get_size_map(name, env);
	if ((fd = open(name, O_RDONLY)) == -1)
		w3_error(3);
	line = NULL;
	map = (char **)malloc(((env->map).mapy + 1) * sizeof(char *));
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = line;
		i++;
		line = NULL;
	}
	map[i] = NULL;
	close(fd);
	free(line);
	return (map);
}

static void		w3_get_size_map(char *name, t_env *env)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		w3_error(3);
	while (get_next_line(fd, &line) == 1)
	{
		if (x == 0)
			x = ft_strlen(line);
		if (x != (int)ft_strlen(line))
			w3_error(2);
		y++;
	}
	(env->map).mapx = x;
	(env->map).mapy = y;
	close(fd);
	free(line);
}
