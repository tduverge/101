/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:18:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:45:37 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

int		make_otab(int **ret, t_point ***table, int *size)
{
	int		x;
	int		y;

	if (!(*table = (t_point **)malloc(sizeof(t_point*) * size[1])))
		return (0);
	y = -1;
	while (++y < size[1])
	{
		if (!((*table)[y] = (t_point *)malloc(sizeof(t_point) * size[0])))
			return (0);
	}
	x = 0;
	while (x < size[0])
	{
		y = 0;
		while (y < size[1])
		{
			(*table)[y][x].x = x - (float)size[0] / 2;
			(*table)[y][x].y = y - (float)size[1] / 2;
			(*table)[y][x].z = 0.5 * ret[y][x];
			y++;
		}
		x++;
	}
	return (1);
}

int		first(char **argv, t_param *p)
{
	int		**ret;
	int		y;

	if (!(ret = parsing(argv[1], &(p->size))))
		return (0);
	if (!(make_otab(ret, &(p->original_tab), p->size)))
		return (0);
	y = -1;
	while (++y < p->size[1])
		free(ret[y]);
	free(ret);
	p->r = 32;
	p->a = 5.2;
	p->b = -6.9;
	p->legend = 1;
	made_matrix(p->a, p->b, p->matrix);
	if (!(modif_tab(p->matrix, p->original_tab, &(p->modify_tab), p->size)))
		return (0);
	zoom_tab(p, p->size);
	center_tab(p, p->size);
	return (1);
}

int		second(t_param *p)
{
	int		y;

	y = 0;
	while (y < p->size[1])
	{
		free(p->modify_tab[y]);
		y++;
	}
	free(p->modify_tab);
	made_matrix(p->a, p->b, p->matrix);
	if (!(modif_tab(p->matrix, p->original_tab, &(p->modify_tab), p->size)))
		return (0);
	zoom_tab(p, p->size);
	center_tab(p, p->size);
	return (1);
}

int		move(int keycode, void *param)
{
	t_param *p;

	p = param;
	mlx_clear_window(p->mlx, p->win);
	if (keycode == 53)
		exit(2);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		change_ang(keycode, p);
	if (keycode == 78 && p->r - 0.5 != 0)
		p->r = p->r - 1;
	if (keycode == 69)
		p->r = p->r + 1;
	if (keycode == 0 || keycode == 12)
		change_alt(p, keycode);
	if (keycode == 37)
		p->legend = p->legend ? 0 : 1;
	if (!(second(p)))
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(2);
	}
	drawer(p);
	return (1);
}

int		main(int argc, char **argv)
{
	t_param		p;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 2);
		return (0);
	}
	if (!(first(argv, &p)))
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, "titre");
	drawer(&p);
	mlx_key_hook(p.win, move, &p);
	mlx_loop(p.mlx);
	return (0);
}
