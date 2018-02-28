/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 11:07:24 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"

static int		calc_len_tab(t_tet *tab)
{
	int i;

	i = 0;
	while (tab[i].shape)
		i++;
	return (i);
}

void			ft_write_shape(t_tet *tab, int *index, int size)
{
	tab->x = index[0];
	tab->y = index[1];
	tab->size = size + 1;
}

void			ft_resolve(t_tet *tab, int size, int *sol, int init_len_tab)
{
	int	index[2];
	int	len_tab;

	index[0] = -1;
	len_tab = calc_len_tab(tab);
	while (++(index[0]) <= size && tab[len_tab - 1].x == -1)
	{
		index[1] = 0;
		while (index[1] <= size && tab[len_tab - 1].x == -1)
		{
			if (tab[1].shape != 0 && test(index, sol, (*tab).shape, size))
			{
				ft_write_shape(tab, index, size);
				ft_resolve(tab + 1, size, sol, init_len_tab);
				ft_delete(index, sol, (*tab).shape);
			}
			else if (test(index, sol, (*tab).shape, size))
				ft_write_shape(tab, index, size);
			index[1]++;
		}
	}
	if (len_tab == init_len_tab && tab[init_len_tab - 1].x == -1)
		ft_resolve(tab, size + 1, sol, init_len_tab);
}
