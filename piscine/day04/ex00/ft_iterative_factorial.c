/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:19:31 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/13 20:48:13 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if (nb == 0)
		return (1);
	if (nb > 0 && nb <= 12)
	{
		while (i <= nb)
		{
			res = res * i;
			i++;
		}
		return (res);
	}
	else
		return (0);
}
