/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 13:06:06 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:40:21 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "libft.h"
# include <math.h>
# define WIN_X 1300
# define WIN_Y 1300

typedef enum		e_fractal
{
	mandel,
	julia,
	burning,
}					t_fractal;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	double		start_x;
	double		end_x;
	double		start_y;
	double		end_y;
	double		x;
	double		y;
	int			color;
	int			stop;
	int			ite;
	t_fractal	choice;
	char		*man_str;
	int			palett[25];
}					t_param;

int					key_funct(int keycode, void *param);
int					mouse_funct(int button, int x, int y, void *param);
void				fill_pixel(char *my_image, int x, int y, int color);
void				fill_pixel_img(char *my_image, int x, int y, int color);
void				fill_pixel_vig(char *my_image, int x, int y, int color);
void				first(t_param *p, int ac);
int					second(t_param *p);
int					color(int ite, t_param *p);
int					rgb(int r, int g, int b);
void				*julia_draw_vig(int x, int y, t_param *p);
void				*julia_draw_img(int x, int y, t_param *p);
void				init_julia(t_param *p);
int					julia_mouse(int x, int y, void *param);
void				*mandel_draw_vig(int x, int y, t_param *p);
void				*mandel_draw_img(int x, int y, t_param *p);
void				init_mandel(t_param *p);
void				legend(t_param *p);
void				calc_pal(t_param *p);
void				init_burning(t_param *p);
void				*burning_draw_img(int x, int y, t_param *p);
void				*burning_draw_vig(int x, int y, t_param *p);
void				init(t_param *p);

#endif
