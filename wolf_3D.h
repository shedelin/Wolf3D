/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:59:48 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/03 14:59:50 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H
# define WIDTH 1024
# define HEIGHT 780
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESC 65307

typedef struct	s_draw
{
	int			start;
	int			end;
	int			x;
	int			side;
}				t_draw;

typedef struct	s_dist
{
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	double		pwall;
}				t_dist;

typedef struct	s_map
{
	char		**map;
	int			mapx;
	int			mapy;
	int			x;
	int			y;
}				t_map;

typedef struct	s_play
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		cam_x;
	double		cam_y;
}				t_play;

typedef struct	s_ray
{
	double		dir_x;
	double		dir_y;
	double		pos_x;
	double		pos_y;
	double		camera_x;
	int			step_x;
	int			step_y;
}				t_ray;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_back;
	char		*data_img;
	int			bpp;
	int			sizeline;
	int			angle;
	t_ray		ray;
	t_dist		dist;
	t_play		play;
	t_map		map;
	t_draw		draw;
	int			move;
}				t_env;

char	**w3_get_map(char *name, t_env *env);
void	w3_error(int error);
void	w3_raycasting(t_env *e);
void	w3_draw(t_env *e);
int		w3_mlx(t_env *e);
void	w3_up(t_env *e, double mv_sp);
void	w3_down(t_env *e, double mv_sp);
void	w3_right(t_env *e, double rt_sp);
void	w3_left(t_env *e, double rt_sp);

#endif /* !WOLF_3D_H */
