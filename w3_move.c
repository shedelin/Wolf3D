/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 21:31:38 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 21:31:40 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "wolf_3D.h"

void	w3_up(t_env *e, double mv_sp)
{
	double	x;
	double	y;

	x = e->play.pos_x;
	y = e->play.pos_y;
	if (e->map.map[(int)(x + e->play.dir_x * mv_sp)][(int)y] != '1')
	{
		if (e->map.map[(int)x][(int)(y + e->play.dir_y * mv_sp)] != '1')
		{
			x += e->play.dir_x * mv_sp;
			y += e->play.dir_y * mv_sp;
		}
	}
	e->play.pos_x = x;
	e->play.pos_y = y;
	w3_raycasting(e);
}

void	w3_down(t_env *e, double mv_sp)
{
	double	x;
	double	y;

	x = e->play.pos_x;
	y = e->play.pos_y;
	if (e->map.map[(int)(x - e->play.dir_x * mv_sp)][(int)y] != '1')
	{
		if (e->map.map[(int)x][(int)(y - e->play.dir_y * mv_sp)] != '1')
		{
			x -= e->play.dir_x * mv_sp;
			y -= e->play.dir_y * mv_sp;
		}
	}
	e->play.pos_x = x;
	e->play.pos_y = y;
	w3_raycasting(e);
}

void	w3_right(t_env *e, double rt_sp)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = e->play.dir_x;
	e->play.dir_x = e->play.dir_x * cos(-rt_sp) - e->play.dir_y * sin(-rt_sp);
	e->play.dir_y = old_dir_x * sin(-rt_sp) + e->play.dir_y * cos(-rt_sp);
	old_plane_x = e->play.cam_x;
	e->play.cam_x = e->play.cam_x * cos(-rt_sp) - e->play.cam_y * sin(-rt_sp);
	e->play.cam_y = old_plane_x * sin(-rt_sp) + e->play.cam_y * cos(-rt_sp);
	w3_raycasting(e);
}

void	w3_left(t_env *e, double rt_sp)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = e->play.dir_x;
	e->play.dir_x = e->play.dir_x * cos(rt_sp) - e->play.dir_y * sin(rt_sp);
	e->play.dir_y = old_dir_x * sin(rt_sp) + e->play.dir_y * cos(rt_sp);
	old_plane_x = e->play.cam_x;
	e->play.cam_x = e->play.cam_x * cos(rt_sp) - e->play.cam_y * sin(rt_sp);
	e->play.cam_y = old_plane_x * sin(rt_sp) + e->play.cam_y * cos(rt_sp);
	w3_raycasting(e);
}
