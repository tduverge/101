/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:45:39 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 19:17:56 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	size_t	len_s2;
	size_t	i;
	char	*res;

	if (!(s1 && s2))
		return (NULL);
	len_s2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len + len_s2 + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len + len_s2)
	{
		res[i] = s2[i - len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
