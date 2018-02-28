/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:14:21 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/13 11:26:42 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	if (!(s1 && s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		res[i] = s2[i - len_s1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
