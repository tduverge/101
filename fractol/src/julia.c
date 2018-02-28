/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 12:56:12 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:41:37 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

void	init_julia(t_param *p)
{
	p->start_x = -2.5;
	p->end_x = 2.5;
	p->start_y = -2.5;
	p->end_y = 2.5;
	p->ite = 50;
	p->x = -0.812921;
	p->y = 0.118393;
	p->stop = 0;
}

int		calc_j(double x, double y, int ite, t_param *p)
{
	double		c[2];
	double		z[2];
	double		sqr[2];
	int			i;

	c[0] = p->x;
	c[1] = p->y;
	z[0] = x;
	z[1] = y;
	sqr[0] = z[0] * z[0];
	sqr[1] = z[1] * z[1];
	i = 0;
	while (i <= ite && sqr[0] + sqr[1] < 4)
	{
		z[1] = z[1] * z[0];
		z[1] += z[1] + c[1];
		z[0] = sqr[0] - sqr[1] + c[0];
		sqr[0] = z[0] * z[0];
		sqr[1] = z[1] * z[1];
		i++;
	}
	return (i);
}

void	*julia_draw_vig(int x, int y, t_param *p)
{
	void		*add;
	char		*man_str;
	int			i[3];
	int			ite;
	double		len[2];

	add = mlx_new_image(p->mlx, x, y);
	man_str = mlx_get_data_addr(add, i, i + 1, i + 2);
	len[0] = (p->end_y - p->start_y) / (y - 1);
	len[1] = (p->end_x - p->start_x) / (x - 1);
	i[0] = 0;
	while (i[0] < y)
	{
		i[1] = 0;
		while (i[1] < x)
		{
			ite = calc_j(i[1] * len[1] + p->start_x,
					i[0] * len[0] + p->start_y, p->ite, p);
			if (ite != p->ite + 1)
				fill_pixel_vig(man_str, i[1], i[0], color(ite, p));
			i[1]++;
		}
		i[0]++;
	}
	return (add);
}

void	*julia_draw_img(int x, int y, t_param *p)
{
	void		*add;
	char		*man_str;
	int			i[3];
	int			ite;
	double		len[2];

	add = mlx_new_image(p->mlx, x, y);
	man_str = mlx_get_data_addr(add, i, i + 1, i + 2);
	len[0] = (p->end_y - p->start_y) / (y - 1);
	len[1] = (p->end_x - p->start_x) / (x - 1);
	i[0] = 0;
	while (i[0] < y)
	{
		i[1] = 0;
		while (i[1] < x)
		{
			ite = calc_j(i[1] * len[1] + p->start_x,
					i[0] * len[0] + p->start_y, p->ite, p);
			if (ite != p->ite + 1)
				fill_pixel_img(man_str, i[1], i[0], color(ite, p));
			i[1]++;
		}
		i[0]++;
	}
	return (add);
}
