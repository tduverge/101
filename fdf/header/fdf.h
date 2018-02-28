/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:36:28 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 11:52:44 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 2540
# define WIN_Y 1440
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "libft.h"
# include "../header/get_next_line.h"

# include <stdio.h>

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*size;
	char			*str_img;
	int				i;
	int				legend;
	t_point			**original_tab;
	t_point			**modify_tab;
	float			a;
	float			b;
	float			r;
	float			matrix[3][3];
}					t_param;

typedef struct		s_segment
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	a;
	float	b;
}					t_segment;

t_point				make_point(float x, float y, float z);
void				make_matrix(t_point a, t_point b, t_point c, float r[3][3]);
void				invert_matrix(float matrix[3][3], float ret[3][3]);
t_point				cross_product(t_point a, t_point b);
t_point				mat_vec_product(float a[3][3], t_point b);
float				vect_norme(t_point a);
int					**parsing(char *argv, int **size);
t_point				cross_product(t_point a, t_point b);
t_point				mat_vec_product(float a[3][3], t_point b);
float				vect_norme(t_point a);
void				drawer(t_param *p);
int					max(int a, int b);
int					min(int a, int b);
int					arr(float a);
void				made_matrix(float a, float b, float matrix[3][3]);
int					modif_tab(float m[3][3], t_point **o_t, t_point ***m_t,
																	int *size);
void				zoom_tab(t_param *p, int *size);
void				center_tab(t_param *p, int *size);
void				change_alt(t_param *p, int keycode);
void				change_ang(int keycode, t_param *p);
void				legend(t_param *p);
void				fill_pixel(char *my_image, int x, int y, int color);

#endif
