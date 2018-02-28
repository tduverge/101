/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_z.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:36 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:01:55 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		test_z1(int x, int y, int *sol, int size)
{
	if (y + 2 > size || x + 1 > size)
		return (0);
	if (sol[x] & (3 << y) || sol[x + 1] & (6 << y))
		return (0);
	sol[x] += 3 << y;
	sol[x + 1] += 6 << y;
	return (1);
}

int		test_z2(int x, int y, int *sol, int size)
{
	if (y - 1 < 0 || x + 2 > size)
		return (0);
	if (sol[x] & (2 << (y - 1)) || sol[x + 1] & (3 << (y - 1)) ||
			sol[x + 2] & (1 << (y - 1)))
		return (0);
	sol[x] += 2 << (y - 1);
	sol[x + 1] += 3 << (y - 1);
	sol[x + 2] += 1 << (y - 1);
	return (1);
}
