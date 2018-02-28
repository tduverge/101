/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 22:27:32 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/15 22:27:35 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int i_max;
	int save;

	i_max = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] >= tab[i_max])
			i_max = i;
		i++;
	}
	save = tab[size - 1];
	tab[size - 1] = tab[i_max];
	tab[i_max] = save;
	if (size >= 2)
		ft_sort_integer_table(tab, size - 1);
}

int		ft_antidote(int i, int j, int k)
{
	int tab[3];

	tab[0] = i;
	tab[1] = j;
	tab[2] = k;
	ft_sort_integer_table(tab, 3);
	return (tab[1]);
}
