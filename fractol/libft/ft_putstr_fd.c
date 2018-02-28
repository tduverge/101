/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:11:35 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:54:23 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	if (!(s))
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
