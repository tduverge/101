/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:21:16 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/13 20:59:24 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int res;

	res = 0;
	if (power > 1)
	{
		res = ft_recursive_power(nb, power - 1) * nb;
		return (res);
	}
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	return (0);
}
