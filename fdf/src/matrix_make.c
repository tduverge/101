/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:26:37 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:13:20 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

t_point			make_point(float x, float y, float z)
{
	t_point		ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void			make_matrix(t_point a, t_point b, t_point c, float ret[3][3])
{
	ret[0][0] = a.x;
	ret[1][0] = a.y;
	ret[2][0] = a.z;
	ret[0][1] = b.x;
	ret[1][1] = b.y;
	ret[2][1] = b.z;
	ret[0][2] = c.x;
	ret[1][2] = c.y;
	ret[2][2] = c.z;
}

void			made_matrix(float a, float b, float matrix[3][3])
{
	t_point		nx;
	t_point		ny;
	t_point		nz;
	float		temp_matrix[3][3];

	nz = make_point(-cos(a) * cos(b), -sin(a) * cos(b), -sin(b));
	nx = make_point(-sin(a), cos(a), 0);
	ny = cross_product(nx, nz);
	make_matrix(nx, ny, nz, temp_matrix);
	invert_matrix(temp_matrix, matrix);
}
