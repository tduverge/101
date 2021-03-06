/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 15:25:07 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:54:19 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

int		calc_burning(double x, double y, int ite)
{
	double		c[2];
	double		z[2];
	double		sqr[2];
	int			i;

	c[0] = x;
	c[1] = y;
	z[0] = 0;
	z[1] = 0;
	sqr[0] = 0;
	sqr[1] = 0;
	i = 0;
	while (i <= ite && sqr[0] + sqr[1] < 4)
	{
		z[1] = fabs(z[0]) * fabs(z[1]);
		z[1] += z[1] + c[1];
		z[0] = sqr[0] - sqr[1] + c[0];
		sqr[0] = z[0] * z[0];
		sqr[1] = z[1] * z[1];
		i++;
	}
	return (i);
}

void	*burning_draw_vig(int x, int y, t_param *p)
{
	void		*add;
	char		*man_str;
	int			i[3];
	int			ite;
	double		len[2];

	add = mlx_new_image(p->mlx, x, y);
	man_str = mlx_get_data_addr(add, i, i + 1, i + 2);
	len[0] = (p->end_x - p->start_x) / (x - 1);
	len[1] = (p->end_y - p->start_y) / (y - 1);
	i[0] = 0;
	while (i[0] < y)
	{
		i[1] = 0;
		while (i[1] < x)
		{
			ite = calc_burning(i[1] * len[0] + p->start_x,
					i[0] * len[1] + p->start_y, p->ite);
			if (ite != p->ite + 1)
				fill_pixel_vig(man_str, i[1], i[0], color(ite, p));
			i[1]++;
		}
		i[0]++;
	}
	return (add);
}

void	*burning_draw_img(int x, int y, t_param *p)
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
			ite = calc_burning(i[1] * len[1] + p->start_x,
					i[0] * len[0] + p->start_y, p->ite);
			if (ite != p->ite + 1)
				fill_pixel_img(man_str, i[1], i[0], color(ite, p));
			i[1]++;
		}
		i[0]++;
	}
	return (add);
}

void	init_burning(t_param *p)
{
	p->start_x = -1.778311;
	p->end_x = 0.973572;
	p->start_y = -1.785372;
	p->end_y = 0.660745;
	p->ite = 50;
}
