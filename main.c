/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:16:54 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/03 14:16:58 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <string.h>
#include "wolf_3D.h"

static void		w3_init_pos(t_env *env);
static void		w3_begin_pos(t_env *env);

int				main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		w3_error(0);
	else if (ac > 2)
		w3_error(1);
	else
	{
		if (((env.map).map = w3_get_map(av[1], &env)) == NULL)
			w3_error(2);
		w3_init_pos(&env);
		w3_raycasting(&env);
	}
	return (0);
}

static void		w3_init_pos(t_env *e)
{
	int		w;
	int		h;

	w3_begin_pos(e);
	e->play.cam_x = 0;
	e->play.cam_y = 0.66;
	e->play.dir_x = -1;
	e->play.dir_y = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT + 119, "Wolf3D");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_back = mlx_xpm_file_to_image(e->mlx, "doom1hd.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img_back, 0, 780);
	e->data_img = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->angle);
}

static void		w3_begin_pos(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < env->map.mapy)
	{
		while (x < env->map.mapx)
		{
			if (env->map.map[y][x] == 'P')
			{
				env->play.pos_x = x;
				env->play.pos_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	w3_error(4);
}
