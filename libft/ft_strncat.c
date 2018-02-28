/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:05:08 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/10 19:12:33 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	i;

	len_s1 = ft_strlen(s1);
	i = 0;
	while (n-- && s2[i])
	{
		s1[len_s1 + i] = s2[i];
		i++;
	}
	s1[len_s1 + i] = '\0';
	return (s1);
}
