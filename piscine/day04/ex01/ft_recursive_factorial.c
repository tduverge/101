/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:40:59 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/13 20:50:34 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int res;

	if (nb > 0 && nb <= 12)
	{
		res = nb * ft_recursive_factorial(nb - 1);
		return (res);
	}
	if (nb == 0)
		return (1);
	return (0);
}
