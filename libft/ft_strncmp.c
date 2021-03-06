/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:52:35 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/15 21:55:52 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] == s22[i] && s11[i] != '\0' && i < n)
		i++;
	if (n == 0)
		return (0);
	else if (i != n)
		return ((int)s11[i] - (int)s22[i]);
	return ((int)s11[i - 1] - (int)s22[i - 1]);
}
