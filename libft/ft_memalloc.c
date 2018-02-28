/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:50:05 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/13 08:50:20 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	if (!(res = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
