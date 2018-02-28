/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 13:04:09 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:44:24 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

void	first(t_param *p, int ac)
{
	void		*add;

	if (ac == 1)
		p->choice = mandel;
	p->color = -93;
	calc_pal(p);
	init_burning(p);
	add = burning_draw_vig(WIN_X / 4, WIN_Y / 4, p);
	mlx_put_image_to_window(p->mlx, p->win, add, 3 * WIN_X / 4, WIN_Y / 2);
	mlx_destroy_image(p->mlx, add);
	init_julia(p);
	add = julia_draw_vig(WIN_X / 4, WIN_Y / 4, p);
	mlx_put_image_to_window(p->mlx, p->win, add, 3 * WIN_X / 4, WIN_Y / 4);
	mlx_destroy_image(p->mlx, add);
	init_mandel(p);
	add = mandel_draw_vig(WIN_X / 4, WIN_Y / 4, p);
	mlx_put_image_to_window(p->mlx, p->win, add, 3 * WIN_X / 4, 0);
	mlx_destroy_image(p->mlx, add);
	init(p);
	second(p);
}

int		second(t_param *p)
{
	void		*add;

	if (p->choice == mandel)
	{
		add = mandel_draw_img(WIN_X * 3 / 4, WIN_Y * 3 / 4, p);
		mlx_put_image_to_window(p->mlx, p->win, add, 0, 0);
		mlx_destroy_image(p->mlx, add);
	}
	else if (p->choice == julia)
	{
		add = julia_draw_img(WIN_X * 3 / 4, WIN_Y * 3 / 4, p);
		mlx_put_image_to_window(p->mlx, p->win, add, 0, 0);
		mlx_destroy_image(p->mlx, add);
	}
	else
	{
		add = burning_draw_img(WIN_X * 3 / 4, WIN_Y * 3 / 4, p);
		mlx_put_image_to_window(p->mlx, p->win, add, 0, 0);
		mlx_destroy_image(p->mlx, add);
	}
	legend(p);
	return (1);
}

int		usage(void)
{
	ft_putstr("usage : ./fractol [choice]\n");
	ft_putstr("choices :\n");
	ft_putstr("\tMandelbrot\n");
	ft_putstr("\tJulia\n");
	ft_putstr("\t\"Burning ship\"\n");
	return (0);
}

void	check_arg(char *av, t_param *p)
{
	if (!ft_strcmp(av, "Mandelbrot"))
		p->choice = mandel;
	else if (!ft_strcmp(av, "Julia"))
		p->choice = julia;
	else if (!ft_strcmp(av, "Burning ship"))
		p->choice = burning;
	else
	{
		usage();
		exit(2);
	}
}

int		main(int ac, char **av)
{
	t_param		p;

	if (ac == 2)
		check_arg(av[1], &p);
	else if (ac != 1)
		return (usage());
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, "Fractol");
	first(&p, ac);
	mlx_key_hook(p.win, key_funct, &p);
	mlx_mouse_hook(p.win, mouse_funct, &p);
	mlx_hook(p.win, 6, (1L << 6), julia_mouse, &p);
	mlx_loop(p.mlx);
	return (0);
}
