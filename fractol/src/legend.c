/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 13:54:42 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:12:17 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

static void			put_back(t_param *p)
{
	int			x;
	int			y;

	x = 0;
	while (x < WIN_X)
	{
		y = WIN_Y * 3 / 4;
		while (y < WIN_Y)
		{
			mlx_pixel_put(p->mlx, p->win, x, y, p->palett[0]);
			y++;
		}
		x++;
	}
	y = 0;
	while (y < WIN_Y * 3 / 4)
	{
		mlx_pixel_put(p->mlx, p->win, WIN_X * 3 / 4, y, p->palett[0]);
		y++;
	}
}

void				legend(t_param *p)
{
	put_back(p);
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 20, 0x00FFFFFF,
			"Click on the images on the right for select or init the fractals");
	mlx_string_put(p->mlx, p->win, WIN_X * 3 / 4, WIN_Y * 3 / 4 + 20, 0xFFFFFF,
			"Number of iteration :  ");
	mlx_string_put(p->mlx, p->win, WIN_X * 3 / 4 + 210, WIN_Y * 3 / 4 + 20,
			0xDCD620, ft_itoa(p->ite));
	mlx_string_put(p->mlx, p->win, WIN_X * 3 / 4, WIN_Y * 3 / 4 + 100, 0xFFFFFF,
			"Julia mouvement :");
	if (p->stop == 0)
		mlx_string_put(p->mlx, p->win, WIN_X * 3 / 4 + 210, WIN_Y * 3 / 4 + 100,
				0xFF00, "ON");
	else
		mlx_string_put(p->mlx, p->win, WIN_X * 3 / 4 + 210, WIN_Y * 3 / 4 + 100,
				0xFF0000, "OFF");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 60, 0x00FFFFFF,
			"Zoom   :             Molette");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 100, 0x00FFFFFF,
			"Move   :             Keyboard Arrow");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 140, 0x00FFFFFF,
			"+ or - :             Change number of iteration");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 180, 0x00FFFFFF,
			"1 or 2 :             Change color");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 220, 0x00FFFFFF,
			"ESC    :             Quit the programm");
}
