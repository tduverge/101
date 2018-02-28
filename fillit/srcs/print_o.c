/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_o.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:15 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:07:26 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

void	print_o(char **board, t_tet *tet)
{
	char	c;
	int		x;
	int		y;

	c = tet->letter;
	x = tet->x;
	y = tet->y;
	board[x][y] = c;
	board[x][y + 1] = c;
	board[x + 1][y] = c;
	board[x + 1][y + 1] = c;
}
