/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:31 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:12:03 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"

static int		test_1(int index[2], int *sol, t_eshape shape, int size)
{
	if (shape == 15)
		return (test_i1(index[0], index[1], sol, size));
	if (shape == 23)
		return (test_l1(index[0], index[1], sol, size));
	if (shape == 27)
		return (test_s1(index[0], index[1], sol, size));
	if (shape == 29)
		return (test_l3(index[0], index[1], sol, size));
	if (shape == 39)
		return (test_t1(index[0], index[1], sol, size));
	return (test_o(index[0], index[1], sol, size));
}

static int		test_2(int index[2], int *sol, t_eshape shape, int size)
{
	if (shape == 57)
		return (test_t3(index[0], index[1], sol, size));
	if (shape == 71)
		return (test_j1(index[0], index[1], sol, size));
	if (shape == 99)
		return (test_z1(index[0], index[1], sol, size));
	if (shape == 113)
		return (test_j3(index[0], index[1], sol, size));
	if (shape == 153)
		return (test_z2(index[0], index[1], sol, size));
	return (test_j2(index[0], index[1], sol, size));
}

int				test(int index[2], int *sol, t_eshape shape, int size)
{
	if (shape < 55)
		return (test_1(index, sol, shape, size));
	if (shape < 280)
		return (test_2(index, sol, shape, size));
	if (shape == 281)
		return (test_t4(index[0], index[1], sol, size));
	if (shape == 305)
		return (test_t2(index[0], index[1], sol, size));
	if (shape == 401)
		return (test_j4(index[0], index[1], sol, size));
	if (shape == 547)
		return (test_l4(index[0], index[1], sol, size));
	if (shape == 561)
		return (test_s2(index[0], index[1], sol, size));
	if (shape == 785)
		return (test_l2(index[0], index[1], sol, size));
	return (test_i2(index[0], index[1], sol, size));
}
