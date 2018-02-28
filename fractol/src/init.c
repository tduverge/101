/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 18:32:32 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:40:12 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

void	init(t_param *p)
{
	if (p->choice == mandel)
		init_mandel(p);
	else if (p->choice == julia)
		init_julia(p);
	else if (p->choice == burning)
		init_burning(p);
}
