/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 21:09:14 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 21:09:18 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf_3D.h"

static void		w3_draw_sky_ground(t_env *e);
static void		w3_draw_wall(t_env *e);
static void		w3_get_color_wall(t_env *e, int i);

void			w3_draw(t_env *e)
{
	w3_draw_sky_ground(e);
	w3_draw_wall(e);
}

static void		w3_draw_sky_ground(t_env *e)
{
	int		i;
	int		s;
	int		g;

	s = 0;
	while (s < e->draw.start)
	{
		i = e->draw.x * e->bpp / 8 + s *e->sizeline;
		e->data_img[i] = 153;
		e->data_img[i + 1] = 102;
		e->data_img[i + 2] = 51;
		s++;
	}
	i = 0;
	g = HEIGHT;
	while (g > e->draw.end)
	{
		i = e->draw.x * e->bpp / 8 + g * e->sizeline;
		e->data_img[i] = 51;
		e->data_img[i + 1] = 51;
		e->data_img[i + 2] = 51;
		g--;
	}
}

static void		w3_draw_wall(t_env *e)
{
	int		i;
	int		x;

	x = e->draw.start;
	while (x <= e->draw.end)
	{
		i = e->draw.x * e->bpp / 8 + x *e->sizeline;
		w3_get_color_wall(e, i);
		x++;
	}
}

static void		w3_get_color_wall(t_env *e, int i)
{
	if (e->draw.side == 1)
	{
		e->data_img[i] = 51;
		e->data_img[i + 1] = 51;
		e->data_img[i + 2] = 255;
	}
	else if (e->draw.side == 2)
	{
		e->data_img[i] = 255;
		e->data_img[i + 1] = 51;
		e->data_img[i + 2] = 51;
	}
	else if (e->draw.side == 3)
	{
		e->data_img[i] = 51;
		e->data_img[i + 1] = 204;
		e->data_img[i + 2] = 51;
	}
	else
	{
		e->data_img[i] = 255;
		e->data_img[i + 1] = 255;
		e->data_img[i + 2] = 51;
	}
}

