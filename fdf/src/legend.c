/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 00:26:45 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 01:16:10 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	square(t_param *p, int x, int y, int pos[2])
{
	int		a;
	int		b;

	a = pos[0];
	while (a <= x + pos[0])
	{
		b = pos[1];
		while (b <= y + pos[1])
		{
			mlx_pixel_put(p->mlx, p->win, a, b, 0x00707070);
			b++;
		}
		a++;
	}
}

void		legend(t_param *p)
{
	char	*str;
	int		pos[2];

	pos[0] = WIN_X - 315;
	pos[1] = 0;
	square(p, 316, 102, pos);
	str = "Legende :";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1], 0x00DC143C, str);
	str = "Cursor key : change view angles";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1] + 20, 0x90EE90, str);
	str = "Q or A     : change altitude";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1] + 35, 0x90EE90, str);
	str = "+ or -     : change zoom";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1] + 50, 0x90EE90, str);
	str = "L          : view legend";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1] + 65, 0x90EE90, str);
	str = "ESC        : close the  program";
	mlx_string_put(p->mlx, p->win, pos[0], pos[1] + 80, 0x90EE90, str);
}
