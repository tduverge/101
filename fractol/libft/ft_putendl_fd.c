/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:11:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:46:57 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!(s))
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
