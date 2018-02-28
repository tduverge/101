/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_board.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:03:44 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	fill_board(char **board)
{
	int		i;
	int		j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[j])
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}