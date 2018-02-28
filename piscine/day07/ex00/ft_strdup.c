/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:28:36 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/20 17:30:26 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len_str;
	int		i;

	len_str = 0;
	while (src[len_str] != '\0')
		len_str++;
	dest = (char*)malloc(sizeof(*dest) * (len_str + 1));
	i = 0;
	while (i <= len_str)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
