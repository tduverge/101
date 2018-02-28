/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_soluce.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:30 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:35:47 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

static void	print_3(t_tet *tet, t_eshape shape, char **board)
{
	if (shape == 15)
		print_i1(board, tet);
	if (shape == 23)
		print_l1(board, tet);
	if (shape == 27)
		print_s1(board, tet);
	if (shape == 29)
		print_l3(board, tet);
	if (shape == 39)
		print_t1(board, tet);
	if (shape == 51)
		print_o(board, tet);
}

static void	print_2(t_tet *tet, t_eshape shape, char **board)
{
	if (shape == 57)
		print_t3(board, tet);
	else if (shape == 71)
		print_j1(board, tet);
	else if (shape == 99)
		print_z1(board, tet);
	else if (shape == 113)
		print_j3(board, tet);
	else if (shape == 153)
		print_z2(board, tet);
	else
		print_j2(board, tet);
}

static void	print_1(t_tet *tet, t_eshape shape, char **board)
{
	if (shape < 55)
		print_3(tet, tet->shape, board);
	else if (shape < 280)
		print_2(tet, tet->shape, board);
	else if (shape == 281)
		print_t4(board, tet);
	else if (shape == 305)
		print_t2(board, tet);
	else if (shape == 401)
		print_j4(board, tet);
	else if (shape == 547)
		print_l4(board, tet);
	else if (shape == 561)
		print_s2(board, tet);
	else if (shape == 785)
		print_l2(board, tet);
	else
		print_i2(board, tet);
}

char		**print_soluce(t_tet *tets)
{
	int		size;
	int		i;
	char	**board;

	i = 0;
	size = tets->size;
	if (!(board = (char**)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	while (i < size)
	{
		board[i] = (char *)malloc((size + 1) * sizeof(char));
		board[i][size] = '\0';
		i++;
	}
	board[i] = 0;
	fill_board(board);
	while (tets->shape != 0)
	{
		print_1(tets, tets->shape, board);
		tets++;
	}
	return (board);
}
