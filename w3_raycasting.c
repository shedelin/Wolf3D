/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 20:42:56 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 20:42:59 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "wolf_3D.h"

static void		w3_get_walldist(t_env *e);
static void		w3_hit_walldist(t_env *e);
static void		w3_get_wallheight(t_env *e);
static void		w3_ns_wall(t_env *e);

void			w3_raycasting(t_env *e)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		e->ray.camera_x = (2 * x) / (double)(WIDTH) - 1;
		e->ray.pos_x = e->play.pos_x;
		e->ray.pos_y = e->play.pos_y;
		e->ray.dir_x = e->play.dir_x + (e->play.cam_x * e->ray.camera_x);
		e->ray.dir_y = e->play.dir_y + (e->play.cam_y * e->ray.camera_x);
		e->map.x = (int)e->ray.pos_x;
		e->map.y = (int)e->ray.pos_y;
		w3_get_walldist(e);
		w3_hit_walldist(e);
		w3_get_wallheight(e);
		e->draw.x = x;
		w3_draw(e);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	w3_mlx(e);
}

static void		w3_get_walldist(t_env *e)
{
	double	rdx;

	rdx = e->ray.dir_x;
	e->dist.delta_x = sqrt(1 + (e->ray.dir_y * e->ray.dir_y) / (rdx * rdx));
	e->dist.delta_y = sqrt(1 + (rdx * rdx) / (e->ray.dir_y * e->ray.dir_y));
	if (rdx < 0)
	{
		e->ray.step_x = -1;
		e->dist.side_x = (e->ray.pos_x - e->map.x) * e->dist.delta_x;
	}
	else
	{
		e->ray.step_x = 1;
		e->dist.side_x = (e->map.x + 1.0 - e->ray.pos_x) * e->dist.delta_x;
	}
	if (e->ray.dir_y < 0)
	{
		e->ray.step_y = -1;
		e->dist.side_y = (e->ray.pos_y - e->map.y) * e->dist.delta_y;
	}
	else
	{
		e->ray.step_y = 1;
		e->dist.side_y = (e->map.y + 1.0 - e->ray.pos_y) * e->dist.delta_y;
	}
}

static void		w3_hit_walldist(t_env *e)
{
	int		hit;
	double	rsy;
	double	w;

	hit = 0;
	while (hit == 0)
	{
		if (e->dist.side_x < e->dist.side_y)
			w3_ns_wall(e);
		else
		{
			e->dist.side_y += e->dist.delta_y;
			e->map.y += e->ray.step_y;
			e->draw.side = 2;
			if (e->draw.side == 2 && e->ray.dir_y > 0)
				e->draw.side = 3;
			rsy = e->ray.step_y;
			w = fabs((e->map.y - e->ray.pos_y + (1 - rsy) / 2) / e->ray.dir_y);
			e->ray.step_y = rsy;
			e->dist.pwall = w;
		}
		if (e->map.map[e->map.x][e->map.y] == '1')
			hit = 1;
	}
}

static void		w3_get_wallheight(t_env *e)
{
	int		line_height;

	line_height = fabs((int)(HEIGHT / e->dist.pwall));
	e->draw.start = -line_height / 2 + HEIGHT / 2;
	if (e->draw.start < 0)
		e->draw.start = 0;
	e->draw.end = line_height / 2 + HEIGHT / 2;
	if (e->draw.end >= HEIGHT)
		e->draw.end = HEIGHT - 1;
}

static void		w3_ns_wall(t_env *e)
{
	double	wall;
	double	rsx;

	wall = e->dist.pwall;
	rsx = e->ray.step_x;
	e->dist.side_x += e->dist.delta_x;
	e->map.x += e->ray.step_x;
	e->draw.side = 0;
	if (e->draw.side == 0 && e->ray.dir_x > 0)
		e->draw.side = 1;
	wall = fabs((e->map.x - e->ray.pos_x + (1 - rsx) / 2) / e->ray.dir_x);
	e->ray.step_x = rsx;
	e->dist.pwall = wall;
}
