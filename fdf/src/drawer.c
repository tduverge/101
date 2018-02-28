/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawer.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:10:23 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:16:13 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

static int		color(float alt)
{
	int		red;
	int		green;
	int		blue;

	red = max(0, min(255, alt * 40 + 180)) << 16;
	green = max(0, min(255, 320 - alt * 80)) << 8;
	blue = max(0, min(255, 400 - alt * 60));
	return (red + green + blue);
}

static void		segment_drawer2(t_point c, t_point d, t_param *p)
{
	t_segment	n;

	n.dx = arr(c.x) - arr(d.x);
	n.dy = arr(c.y) - arr(d.y);
	if (abs(n.dy) >= abs(n.dx) && n.dy != 0)
	{
		n.a = (float)n.dx / n.dy;
		n.b = arr(c.x) - n.a * arr(c.y);
		n.y = arr(c.y);
		while (n.y != arr(d.y))
		{
			n.x = arr(n.a * n.y + n.b);
			fill_pixel(p->str_img, n.x, n.y,
					color(((n.y - c.y) / (d.y - c.y) * (d.z - c.z) + c.z)));
			n.y = (n.dy > 0) ? n.y - 1 : n.y + 1;
		}
	}
}

static void		segment_drawer(t_point c, t_point d, t_param *p)
{
	t_segment	n;

	n.dx = arr(c.x) - arr(d.x);
	n.dy = arr(c.y) - arr(d.y);
	if (abs(n.dx) >= abs(n.dy) && n.dx != 0)
	{
		n.a = (float)n.dy / n.dx;
		n.b = arr(c.y) - n.a * arr(c.x);
		n.x = arr(c.x);
		while (n.x != arr(d.x))
		{
			n.y = arr(n.a * n.x + n.b);
			fill_pixel(p->str_img, n.x, n.y,
					color(((n.x - c.x) / (d.x - c.x) * (d.z - c.z) + c.z)));
			n.x = (n.dx > 0) ? n.x - 1 : n.x + 1;
		}
	}
	segment_drawer2(c, d, p);
}

void			restart_z(t_param *p)
{
	int		x;
	int		y;

	y = 0;
	while (y < p->size[1])
	{
		x = 0;
		while (x < p->size[0])
		{
			p->modify_tab[y][x].z = p->original_tab[y][x].z;
			x++;
		}
		y++;
	}
}

void			drawer(t_param *p)
{
	int			x;
	int			y;
	t_point		a;

	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->str_img = mlx_get_data_addr(p->img, (int*)&(a.x),
			(int*)&(a.y), (int*)&(a.z));
	restart_z(p);
	x = -1;
	while (++x < p->size[0])
	{
		y = -1;
		while (++y < p->size[1])
		{
			if (x + 1 < p->size[0])
				segment_drawer(p->modify_tab[y][x + 1], p->modify_tab[y][x], p);
			if (y + 1 < p->size[1])
				segment_drawer(p->modify_tab[y + 1][x], p->modify_tab[y][x], p);
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
	if (p->legend == 1)
		legend(p);
}
