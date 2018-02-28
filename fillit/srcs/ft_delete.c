/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:53:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:14:11 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"

static void		delete_1(int index[2], int *sol, t_eshape shape)
{
	if (shape == 15)
		delete_i1(index[0], index[1], sol);
	else if (shape == 23)
		delete_l1(index[0], index[1], sol);
	else if (shape == 27)
		delete_s1(index[0], index[1], sol);
	else if (shape == 29)
		delete_l3(index[0], index[1], sol);
	else if (shape == 39)
		delete_t1(index[0], index[1], sol);
	else
		delete_o(index[0], index[1], sol);
}

static void		delete_2(int index[2], int *sol, t_eshape shape)
{
	if (shape == 57)
		delete_t3(index[0], index[1], sol);
	else if (shape == 71)
		delete_j1(index[0], index[1], sol);
	else if (shape == 99)
		delete_z1(index[0], index[1], sol);
	else if (shape == 113)
		delete_j3(index[0], index[1], sol);
	else if (shape == 153)
		delete_z2(index[0], index[1], sol);
	else
		delete_j2(index[0], index[1], sol);
}

void			ft_delete(int index[2], int *sol, t_eshape shape)
{
	if (shape < 55)
		delete_1(index, sol, shape);
	else if (shape < 280)
		delete_2(index, sol, shape);
	else if (shape == 281)
		delete_t4(index[0], index[1], sol);
	else if (shape == 305)
		delete_t2(index[0], index[1], sol);
	else if (shape == 401)
		delete_j4(index[0], index[1], sol);
	else if (shape == 547)
		delete_l4(index[0], index[1], sol);
	else if (shape == 561)
		delete_s2(index[0], index[1], sol);
	else if (shape == 785)
		delete_l2(index[0], index[1], sol);
	else
		delete_i2(index[0], index[1], sol);
}
