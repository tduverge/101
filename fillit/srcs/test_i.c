/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_i.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:35 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 10:43:15 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		test_i1(int x, int y, int *sol, int size)
{
	if (y + 3 > size)
		return (0);
	if (sol[x] & (15 << y))
		return (0);
	sol[x] += 15 << y;
	return (1);
}

int		test_i2(int x, int y, int *sol, int size)
{
	if (x + 3 > size)
		return (0);
	if (sol[x] & (1 << y) || sol[x + 1] & (1 << y) ||
			sol[x + 2] & (1 << y) || sol[x + 3] & (1 << y))
		return (0);
	sol[x] += 1 << y;
	sol[x + 1] += 1 << y;
	sol[x + 2] += 1 << y;
	sol[x + 3] += 1 << y;
	return (1);
}
