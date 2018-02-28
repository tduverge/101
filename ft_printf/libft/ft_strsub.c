/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 13:33:14 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 19:13:17 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"
#include "stdlib.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(tab = (char *)malloc(sizeof(*tab) * (len) + 1)))
			return (NULL);
		while (s[start] && i < len)
		{
			tab[i] = s[start++];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
