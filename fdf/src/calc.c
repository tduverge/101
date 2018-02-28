/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 16:01:30 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:02:24 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int		arr(float a)
{
	if (a - floor(a) >= 0.5)
		return ((int)ceil(a));
	return ((int)floor(a));
}
