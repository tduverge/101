/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_j3.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:10 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:09:43 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

void	print_j3(char **board, t_tet *tet)
{
	char	c;
	int		x;
	int		y;

	c = tet->letter;
	x = tet->x;
	y = tet->y;
	board[x][y] = c;
	board[x + 1][y] = c;
	board[x + 1][y + 1] = c;
	board[x + 1][y + 2] = c;
}
