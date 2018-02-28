/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:12:15 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:13:59 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	save;

	if (!(s))
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		save = s[i];
		s[i] = s[len - 1];
		s[len - 1] = save;
		i++;
		len--;
	}
	return (s);
}
