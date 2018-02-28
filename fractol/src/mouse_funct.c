/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_funct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 15:08:54 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:57:09 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

static void	zoom(int button, int x, int y, t_param *p)
{
	double		percent_x;
	double		percent_y;
	double		size_x;
	double		size_y;

	percent_x = (double)x / ((WIN_X ? WIN_X : 1) * 3 / 4);
	percent_y = (double)y / ((WIN_Y ? WIN_Y : 1) * 3 / 4);
	size_x = p->end_x - p->start_x;
	size_y = p->end_y - p->start_y;
	if (button == 5)
	{
		p->start_x += size_x * 0.2 * percent_x;
		p->end_x -= size_x * 0.2 * (1 - percent_x);
		p->start_y += size_y * 0.2 * percent_y;
		p->end_y -= size_y * 0.2 * (1 - percent_y);
	}
	if (button == 4)
	{
		p->start_x -= size_x * 0.2 * percent_x;
		p->end_x += size_x * 0.2 * (1 - percent_x);
		p->start_y -= size_y * 0.2 * percent_y;
		p->end_y += size_y * 0.2 * (1 - percent_y);
	}
}

int			mouse_funct(int button, int x, int y, void *param)
{
	t_param		*p;

	p = param;
	if (button == 1 && (x > WIN_X * 3 / 4))
	{
		if (y < WIN_Y / 4)
		{
			p->choice = mandel;
			init_mandel(p);
		}
		else if (y < WIN_Y / 2)
		{
			p->choice = julia;
			init_julia(p);
		}
		else if (y < WIN_Y * 3 / 4)
		{
			p->choice = burning;
			init_burning(p);
		}
	}
	if (button == 4 || button == 5)
		zoom(button, x, y, p);
	second(p);
	return (0);
}

int			julia_mouse(int x, int y, void *param)
{
	t_param		*p;

	p = param;
	if (p->choice == julia && x < 3 * WIN_X / 4 &&
			y < 3 * WIN_Y / 4 && p->stop == 0)
	{
		p->x = (double)x / (3 * WIN_X / 4) * (p->end_x - p->start_x)
			+ p->start_x;
		p->y = (double)y / (3 * WIN_Y / 4) * (p->end_y - p->start_y)
			+ p->start_y;
		second(p);
	}
	return (0);
}
