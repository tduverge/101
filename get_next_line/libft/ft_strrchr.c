/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:12:15 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:13:59 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;
	size_t i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == (unsigned char)c)
			return ((char *)s + len - i);
		i++;
	}
	return (NULL);
}
