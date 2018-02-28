/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsubf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 16:32:45 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:53:42 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char		*sptr;

	if (!s)
		return (NULL);
	sptr = ft_strsub(s, start, len);
	ft_strdel((char **)&s);
	return (sptr);
}
