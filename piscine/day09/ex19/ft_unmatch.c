/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:15:30 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/16 16:15:33 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int j;
	int check;

	i = 0;
	while (i < length)
	{
		check = 0;
		j = 0;
		while (j < length)
		{
			if (j == i)
				j++;
			if (tab[i] == tab[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (tab[i]);
		i++;
	}
	return (0);
}
