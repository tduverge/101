/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_l2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:15 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:08:45 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

void	print_l2(char **board, t_tet *tet)
{
	char	c;
	int		x;
	int		y;

	c = tet->letter;
	x = tet->x;
	y = tet->y;
	board[x][y] = c;
	board[x + 1][y] = c;
	board[x + 2][y] = c;
	board[x + 2][y + 1] = c;
}
