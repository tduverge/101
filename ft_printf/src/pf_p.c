/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_p.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 11:18:10 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 11:27:43 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		pf_p(va_list ap, t_flags *flags, char **str, int len)
{
	flags->hashtag = 1;
	flags->modif = l;
	return (pf_base(ap, flags, str, len));
}
