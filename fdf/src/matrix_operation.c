/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_operation.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:38:14 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 17:46:45 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

t_point		cross_product(t_point a, t_point b)
{
	t_point		ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return (ret);
}

t_point		mat_vec_product(float a[3][3], t_point b)
{
	t_point		ret;

	ret.x = a[0][0] * b.x + a[0][1] * b.y + a[0][2] * b.z;
	ret.y = a[1][0] * b.x + a[1][1] * b.y + a[1][2] * b.z;
	ret.z = a[2][0] * b.x + a[2][1] * b.y + a[2][2] * b.z;
	return (ret);
}

float		vect_norme(t_point a)
{
	float	ret;

	ret = sqrtf(powf(a.x, 2) + powf(a.y, 2) + powf(a.z, 2));
	return (ret);
}
