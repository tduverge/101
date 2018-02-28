/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:17:31 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/16 16:17:36 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int max;

	max = 0;
	while (*tab)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	return (max);
}
