/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:50:50 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:50:50 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putnbr(int n)
{
	long nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar('-');
		nl = -nl;
	}
	if (nl >= 10)
		ft_putnbr((int)(nl / 10));
	ft_putchar(nl % 10 + '0');
}
