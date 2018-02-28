/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_j.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:35 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:43:12 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		test_j1(int x, int y, int *sol, int size)
{
	if (y + 2 > size || x + 1 > size)
		return (0);
	if (sol[x] & (7 << y) || sol[x + 1] & (4 << y))
		return (0);
	sol[x] += 7 << y;
	sol[x + 1] += 4 << y;
	return (1);
}

int		test_j2(int x, int y, int *sol, int size)
{
	if (y + 1 > size || x + 2 > size)
		return (0);
	if (sol[x] & (3 << y) || sol[x + 1] & (1 << y) ||
			sol[x + 2] & (1 << y))
		return (0);
	sol[x] += 3 << y;
	sol[x + 1] += 1 << y;
	sol[x + 2] += 1 << y;
	return (1);
}

int		test_j3(int x, int y, int *sol, int size)
{
	if (x + 1 > size || y + 2 > size)
		return (0);
	if (sol[x] & (1 << y) || sol[x + 1] & (7 << y))
		return (0);
	sol[x] += 1 << y;
	sol[x + 1] += 7 << y;
	return (1);
}

int		test_j4(int x, int y, int *sol, int size)
{
	if (x + 2 > size || y - 1 < 0)
		return (0);
	if (sol[x] & (2 << (y - 1)) || sol[x + 1] & (2 << (y - 1)) ||
			sol[x + 2] & (3 << (y - 1)))
		return (0);
	sol[x] += 2 << (y - 1);
	sol[x + 1] += 2 << (y - 1);
	sol[x + 2] += 3 << (y - 1);
	return (1);
}
