/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_l.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:35 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:02:48 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		test_l1(int x, int y, int *sol, int size)
{
	if (y + 2 > size || x + 1 > size)
		return (0);
	if (sol[x] & (7 << y) || sol[x + 1] & (1 << y))
		return (0);
	sol[x] += 7 << y;
	sol[x + 1] += 1 << y;
	return (1);
}

int		test_l2(int x, int y, int *sol, int size)
{
	if (y + 1 > size || x + 2 > size)
		return (0);
	if (sol[x] & (1 << y) || sol[x + 1] & (1 << y) ||
			sol[x + 2] & (3 << y))
		return (0);
	sol[x] += 1 << y;
	sol[x + 1] += 1 << y;
	sol[x + 2] += 3 << y;
	return (1);
}

int		test_l3(int x, int y, int *sol, int size)
{
	if (x + 1 > size || y - 2 < 0)
		return (0);
	if (sol[x] & (4 << (y - 2)) || sol[x + 1] & (7 << (y - 2)))
		return (0);
	sol[x] += 4 << (y - 2);
	sol[x + 1] += 7 << (y - 2);
	return (1);
}

int		test_l4(int x, int y, int *sol, int size)
{
	if (x + 2 > size || y + 1 > size)
		return (0);
	if (sol[x] & (3 << y) || sol[x + 1] & (2 << y) ||
			sol[x + 2] & (2 << y))
		return (0);
	sol[x] += 3 << y;
	sol[x + 1] += 2 << y;
	sol[x + 2] += 2 << y;
	return (1);
}
