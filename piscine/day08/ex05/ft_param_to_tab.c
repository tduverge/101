/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:01 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/22 20:24:08 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

void				size_of_param(t_stock_par *res, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		res[i].size_param = 0;
		while (av[i][j])
		{
			res[i].size_param++;
			j++;
		}
		i++;
	}
}

void				copy_of_param(t_stock_par *res, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		res[i].copy = (char*)malloc(sizeof(char) * (res[i].size_param + 1));
		j = 0;
		while (av[i][j])
		{
			res[i].copy[j] = av[i][j];
			j++;
		}
		res[i].copy[j] = '\0';
		i++;
	}
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*res;
	int				i;

	res = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	size_of_param(res, ac, av);
	i = 0;
	while (i < ac)
	{
		res[i].str = av[i];
		res[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	copy_of_param(res, ac, av);
	res[ac].str = NULL;
	return (res);
}
