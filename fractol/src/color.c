/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 12:55:07 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:52:58 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

int			rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

void		calc_pal(t_param *p)
{
	double		t;
	int			r;
	int			g;
	int			b;
	int			i;

	i = 0;
	while (i < 25)
	{
		t = (double)1 / (i + 1);
		r = 255 * (0.5f + 0.5f * cos(2 * M_PI * (t + (double)p->color / 25)));
		g = 255 * (0.5f + 0.5f * sin(2 * M_PI * (t + p->color * 0.33 / 25)));
		b = 255 * (0.5f + 0.5f * sin(2 * M_PI * (t + p->color * 0.67 / 25)));
		p->palett[i] = rgb(r, g, b);
		i++;
	}
}

int			color(int ite, t_param *p)
{
	return (p->palett[ite % 25]);
}
