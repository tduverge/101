/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_funct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 13:19:37 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:01:28 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

static void		move(int k, t_param *p, double size_x, double size_y)
{
	if (k == 123)
	{
		p->start_x -= size_x * 0.1;
		p->end_x -= size_x * 0.1;
	}
	if (k == 124)
	{
		p->start_x += size_x * 0.1;
		p->end_x += size_x * 0.1;
	}
	if (k == 125)
	{
		p->start_y += size_y * 0.1;
		p->end_y += size_y * 0.1;
	}
	if (k == 126)
	{
		p->start_y -= size_y * 0.1;
		p->end_y -= size_y * 0.1;
	}
}

int				key_funct(int keycode, void *param)
{
	t_param		*p;
	double		size_x;
	double		size_y;

	p = param;
	size_x = p->end_x - p->start_x;
	size_y = p->end_y - p->start_y;
	if (123 <= keycode && keycode <= 126)
		move(keycode, p, size_x, size_y);
	if (keycode == 69)
		p->ite += 10;
	if (keycode == 78 && p->ite != 10)
		p->ite -= 10;
	if (keycode == 53)
		exit(2);
	if (keycode == 1)
		p->stop = (p->stop == 1) ? 0 : 1;
	if (keycode == 83 || keycode == 84)
	{
		p->color = (keycode == 83) ? p->color + 1 : p->color - 1;
		calc_pal(p);
	}
	second(p);
	return (0);
}
