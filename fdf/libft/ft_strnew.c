/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:12:14 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:53:15 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
