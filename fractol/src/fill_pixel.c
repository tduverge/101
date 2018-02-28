/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_pixel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 08:53:37 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 13:42:46 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fractol.h"

void	fill_pixel(char *my_image, int x, int y, int color)
{
	int		start;

	if ((0 <= y && y < WIN_Y) && (0 <= x && x < WIN_X))
	{
		start = 4 * (x + WIN_X * y);
		my_image[start] = (color & 0xFF);
		my_image[start + 1] = (color & 0xFF00) >> 8;
		my_image[start + 2] = (color & 0xFF0000) >> 16;
	}
}

void	fill_pixel_img(char *my_image, int x, int y, int color)
{
	int		start;

	if ((0 <= y && y < WIN_Y * 3 / 4) && (0 <= x && x < WIN_X * 3 / 4))
	{
		start = 4 * (x + WIN_X * 3 / 4 * y);
		my_image[start] = (color & 0xFF);
		my_image[start + 1] = (color & 0xFF00) >> 8;
		my_image[start + 2] = (color & 0xFF0000) >> 16;
	}
}

void	fill_pixel_vig(char *my_image, int x, int y, int color)
{
	int		start;

	if ((0 <= y && y < WIN_Y / 4) && (0 <= x && x < WIN_X / 4))
	{
		start = 4 * (x + WIN_X / 4 * y);
		my_image[start] = (color & 0xFF);
		my_image[start + 1] = (color & 0xFF00) >> 8;
		my_image[start + 2] = (color & 0xFF0000) >> 16;
	}
}
