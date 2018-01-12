/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 21:10:02 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 21:10:03 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include "libft.h"
#include "wolf_3D.h"

static int	key_press_event(int keycode, t_env *e);
static int	key_release_event(int keycode, t_env *e);
static int	loop_event(t_env *e);
static int	expose_hook(t_env *e);

int			w3_mlx(t_env *e)
{
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_press_event, e);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release_event, e);
	mlx_loop_hook(e->mlx, &loop_event, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

static int	key_press_event(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->move = 1;
	if (keycode == KEY_DOWN)
		e->move = 2;
	if (keycode == KEY_RIGHT)
		e->move = 3;
	if (keycode == KEY_LEFT)
		e->move = 4;
	if (keycode == KEY_ESC)
	{
		ft_tabdel(&e->map.map);
		exit(0);
	}
	return (0);
}

static int	key_release_event(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->move = 0;
	if (keycode == KEY_DOWN)
		e->move = 0;
	if (keycode == KEY_RIGHT)
		e->move = 0;
	if (keycode == KEY_LEFT)
		e->move = 0;
	return (0);
}

static int	loop_event(t_env *e)
{
	if (e->move == 1)
		w3_up(e, 0.12);
	if (e->move == 2)
		w3_down(e, 0.09);
	if (e->move == 3)
		w3_right(e, 0.02);
	if (e->move == 4)
		w3_left(e, 0.02);
	return (0);
}

static int	expose_hook(t_env *e)
{
	w3_raycasting(e);
	return (0);
}
