/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:11:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:13:58 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*a;
	unsigned char	nb;

	i = 0;
	a = b;
	nb = (unsigned char)c;
	while (i < len)
	{
		a[i] = nb;
		i++;
	}
	return (b);
}
