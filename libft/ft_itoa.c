/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:54:55 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/15 23:14:39 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len_n(long n, int *i)
{
	if (n < 0)
	{
		n = -n;
		(*i)++;
	}
	if (n >= 10)
		ft_len_n(n / 10, i);
	*i = *i + 1;
}

static void	ft_itoa_rec(long n, int i, char *res, int len_n)
{
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n >= 10)
		ft_itoa_rec(n / 10, i + 1, res, len_n);
	res[len_n - i] = n % 10 + '0';
}

char		*ft_itoa(int n)
{
	int		len_n;
	char	*res;
	long	n_long;

	n_long = n;
	len_n = 0;
	ft_len_n(n_long, &len_n);
	if (!(res = (char*)malloc(sizeof(char) * (len_n + 1))))
		return (NULL);
	ft_itoa_rec(n_long, 1, res, len_n);
	res[len_n] = '\0';
	return (res);
}
