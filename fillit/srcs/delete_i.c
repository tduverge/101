/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_i.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 11:14:29 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:14:31 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	delete_i1(int x, int y, int *sol)
{
	sol[x] -= 15 << y;
}

void	delete_i2(int x, int y, int *sol)
{
	sol[x] -= 1 << y;
	sol[x + 1] -= 1 << y;
	sol[x + 2] -= 1 << y;
	sol[x + 3] -= 1 << y;
}