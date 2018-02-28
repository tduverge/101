/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:17 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/13 20:59:30 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	res = nb;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
