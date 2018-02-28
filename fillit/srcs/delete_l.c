/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_l.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:54:15 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:02:10 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	delete_l1(int x, int y, int *sol)
{
	sol[x] -= 7 << y;
	sol[x + 1] -= 1 << y;
}

void	delete_l2(int x, int y, int *sol)
{
	sol[x] -= 1 << y;
	sol[x + 1] -= 1 << y;
	sol[x + 2] -= 3 << y;
}

void	delete_l3(int x, int y, int *sol)
{
	sol[x] -= 4 << (y - 2);
	sol[x + 1] -= 7 << (y - 2);
}

void	delete_l4(int x, int y, int *sol)
{
	sol[x] -= 3 << y;
	sol[x + 1] -= 2 << y;
	sol[x + 2] -= 2 << y;
}
