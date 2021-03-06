/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pgcd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:11:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:46:40 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_pgcd(int n_1, int n_2)
{
	int pgcd;
	int i;

	pgcd = 1;
	i = 1;
	while (i <= n_1 || i <= n_2)
	{
		if (n_1 % i == 0 && n_2 % i == 0)
			pgcd = i;
		i++;
	}
	return (pgcd);
}
