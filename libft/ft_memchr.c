/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:13:41 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/15 21:45:12 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	needle;

	needle = (unsigned char)c;
	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s1 == needle)
			return ((void *)s1);
		s1++;
		i++;
	}
	return (NULL);
}
