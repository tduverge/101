/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rqnge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:05:33 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/07 15:25:53 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
		return (NULL);
	i = min;
	tab = malloc(sizeof(int) * (max - min));
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	return (tab);
}
