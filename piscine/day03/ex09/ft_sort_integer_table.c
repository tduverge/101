/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 23:46:19 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/11 18:37:04 by tduverge         ###   ########.fr       */
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
