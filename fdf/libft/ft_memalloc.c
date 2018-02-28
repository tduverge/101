/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:11:14 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:45:59 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	if (!(res = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
