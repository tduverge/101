/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 16:09:54 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:44:58 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

int		modif_tab(float mat[3][3], t_point **o_tab, t_point ***m_tab, int *size)
{
	int		x;
	int		y;

	if (!(*m_tab = (t_point **)malloc(sizeof(t_point*) * size[1])))
		return (0);
	y = 0;
	while (y < size[1])
	{
		if (!((*m_tab)[y] = (t_point *)malloc(sizeof(t_point) * size[0])))
			return (0);
		y++;
	}
	x = 0;
	while (x < size[0])
	{
		y = 0;
		while (y < size[1])
		{
			(*m_tab)[y][x] = mat_vec_product(mat, o_tab[y][x]);
			y++;
		}
		x++;
	}
	return (1);
}

void	zoom_tab(t_param *p, int *size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size[0])
	{
		y = 0;
		while (y < size[1])
		{
			p->modify_tab[y][x].x = p->r * p->modify_tab[y][x].x;
			p->modify_tab[y][x].y = p->r * p->modify_tab[y][x].y;
			p->modify_tab[y][x].z = p->r * p->modify_tab[y][x].z;
			y++;
		}
		x++;
	}
}

void	center_tab(t_param *p, int *size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size[0])
	{
		y = 0;
		while (y < size[1])
		{
			p->modify_tab[y][x].x += WIN_X / 2;
			p->modify_tab[y][x].y = WIN_Y / 2 - p->modify_tab[y][x].y;
			y++;
		}
		x++;
	}
}

void	change_alt(t_param *p, int keycode)
{
	int		x;
	int		y;
	float	alt;

	if (keycode == 12)
		alt = 1.1;
	if (keycode == 0)
		alt = 0.9;
	x = 0;
	while (x < p->size[0])
	{
		y = 0;
		while (y < p->size[1])
		{
			p->original_tab[y][x].z *= alt;
			y++;
		}
		x++;
	}
}

void	change_ang(int keycode, t_param *p)
{
	if (keycode == 123)
		p->a = p->a - 0.1;
	if (keycode == 124)
		p->a = p->a + 0.1;
	if (keycode == 125)
		p->b = p->b - 0.1;
	if (keycode == 126)
		p->b = p->b + 0.1;
}
