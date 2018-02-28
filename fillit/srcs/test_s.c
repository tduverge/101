/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:36 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:02:36 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		test_s1(int x, int y, int *sol, int size)
{
	if (y + 1 > size || y - 1 < 0 || x + 1 > size)
		return (0);
	if (sol[x] & (6 << (y - 1)) || sol[x + 1] & (3 << (y - 1)))
		return (0);
	sol[x] += 6 << (y - 1);
	sol[x + 1] += 3 << (y - 1);
	return (1);
}

int		test_s2(int x, int y, int *sol, int size)
{
	if (y + 1 > size || x + 2 > size)
		return (0);
	if (sol[x] & (1 << y) || sol[x + 1] & (3 << y) ||
			sol[x + 2] & (2 << y))
		return (0);
	sol[x] += 1 << y;
	sol[x + 1] += 3 << y;
	sol[x + 2] += 2 << y;
	return (1);
}
