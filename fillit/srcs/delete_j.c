/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_j.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:53:20 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:01:34 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	delete_j1(int x, int y, int *sol)
{
	sol[x] -= 7 << y;
	sol[x + 1] -= 4 << y;
}

void	delete_j2(int x, int y, int *sol)
{
	sol[x] -= 3 << y;
	sol[x + 1] -= 1 << y;
	sol[x + 2] -= 1 << y;
}

void	delete_j3(int x, int y, int *sol)
{
	sol[x] -= 1 << y;
	sol[x + 1] -= 7 << y;
}

void	delete_j4(int x, int y, int *sol)
{
	sol[x] -= 2 << (y - 1);
	sol[x + 1] -= 2 << (y - 1);
	sol[x + 2] -= 3 << (y - 1);
}
