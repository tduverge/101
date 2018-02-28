/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:26:33 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/15 21:51:21 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = dst;
	source = (unsigned char *)src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		if (*source == (unsigned char)c)
			return (dest);
		source++;
		n--;
	}
	return (NULL);
}
