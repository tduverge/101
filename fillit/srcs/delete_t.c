/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_t.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 10:56:43 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:02:29 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	delete_t1(int x, int y, int *sol)
{
	sol[x] -= 7 << y;
	sol[x + 1] -= 2 << y;
}

void	delete_t2(int x, int y, int *sol)
{
	sol[x] -= 1 << y;
	sol[x + 1] -= 3 << y;
	sol[x + 2] -= 1 << y;
}

void	delete_t3(int x, int y, int *sol)
{
	sol[x] -= 2 << (y - 1);
	sol[x + 1] -= 7 << (y - 1);
}

void	delete_t4(int x, int y, int *sol)
{
	sol[x] -= 2 << (y - 1);
	sol[x + 1] -= 3 << (y - 1);
	sol[x + 2] -= 2 << (y - 1);
}
