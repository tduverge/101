/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:45:13 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/13 13:03:13 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len_s;
	size_t	end;
	char	*res;

	if (!(s))
		return (NULL);
	len_s = ft_strlen(s);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = len_s - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end != 0 &&
			len_s != 0)
		end--;
	if (end == 0 || len_s == 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		*res = '\0';
		return (res);
	}
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
