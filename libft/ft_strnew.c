/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:52:57 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/13 15:34:23 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
