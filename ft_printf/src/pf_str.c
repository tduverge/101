/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_str.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 12:29:57 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/25 19:17:27 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			pf_str(char **format, char **str, int len)
{
	int			i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	tmp = *str;
	while ((*format)[i] != '%' && (*format)[i])
		i++;
	if (!(tmp2 = ft_strsub(*format, 0, i)))
		return (-1);
	if (!(*str = ft_strnjoin(*str, tmp2, len)))
	{
		*str = tmp;
		free(tmp2);
		return (-1);
	}
	free(tmp);
	free(tmp2);
	*format += i;
	return (i);
}
