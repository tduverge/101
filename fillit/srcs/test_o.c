/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_o.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:35 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:02:48 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	test_o(int x, int y, int *sol, int size)
{
	if (x + 1 > size || y + 1 > size)
		return (0);
	if (sol[x] & (3 << y) || sol[x + 1] & (3 << y))
		return (0);
	sol[x] += 3 << y;
	sol[x + 1] += 3 << y;
	return (1);
}
