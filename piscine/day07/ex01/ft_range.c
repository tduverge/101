/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:28:44 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/20 21:54:37 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *res;
	int len;
	int i;

	len = max - min;
	if (len <= 0)
	{
		res = NULL;
		return (res);
	}
	res = (int*)malloc(sizeof(*res) * (max - min));
	i = 0;
	while (i + min < max)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
