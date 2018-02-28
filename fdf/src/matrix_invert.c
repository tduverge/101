/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_invert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:59:12 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 13:15:45 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

static void			transpose(float matrix[3][3])
{
	float		swap;
	int			x;
	int			y;

	x = 0;
	while (x < 3)
	{
		y = x + 1;
		while (y < 3)
		{
			swap = matrix[y][x];
			matrix[y][x] = matrix[x][y];
			matrix[x][y] = swap;
			y++;
		}
		x++;
	}
}

static float		det_partial(float mat[3][3], int x, int y)
{
	int		a;
	int		b;
	int		c;
	int		d;
	float	ret;

	a = (x == 0) ? 1 : 0;
	b = (x == a + 1) ? a + 2 : a + 1;
	c = (y == 0) ? 1 : 0;
	d = (y == c + 1) ? c + 2 : c + 1;
	ret = mat[c][a] * mat[d][b] - mat[d][a] * mat[c][b];
	return (ret);
}

static float		det(float mat[3][3])
{
	float		ret;

	ret = mat[0][0] * mat[1][1] * mat[2][2];
	ret = ret + mat[0][1] * mat[1][2] * mat[2][0];
	ret = ret + mat[0][2] * mat[1][0] * mat[2][1];
	ret = ret - mat[0][2] * mat[1][1] * mat[2][0];
	ret = ret - mat[0][1] * mat[1][0] * mat[2][2];
	ret = ret - mat[0][0] * mat[1][2] * mat[2][1];
	return (ret);
}

void				invert_matrix(float matrix[3][3], float re[3][3])
{
	int		x;
	int		y;
	float	deter;

	transpose(matrix);
	deter = 1 / det(matrix);
	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			re[y][x] = pow(-1, x + y) * deter * det_partial(matrix, x, y);
			y++;
		}
		x++;
	}
	transpose(matrix);
}
