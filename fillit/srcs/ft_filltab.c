/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filltab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:03:28 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"
#include <stdio.h>

static int		ft_isvalidshape(int count, int i)
{
	int	tab[19];

	tab[0] = 0b110011;
	tab[1] = 0b1111;
	tab[2] = 0b1000100010001;
	tab[3] = 0b11011;
	tab[4] = 0b1000110001;
	tab[5] = 0b1100011;
	tab[6] = 0b10011001;
	tab[7] = 0b10111;
	tab[8] = 0b1100010001;
	tab[9] = 0b11101;
	tab[10] = 0b1000100011;
	tab[11] = 0b1000111;
	tab[12] = 0b100010011;
	tab[13] = 0b1110001;
	tab[14] = 0b110010001;
	tab[15] = 0b100111;
	tab[16] = 0b100110001;
	tab[17] = 0b111001;
	tab[18] = 0b100011001;
	while (i <= 18 && i != -10)
		(tab[i] == count ? i = -10 : i++);
	return (i == -10 ? 1 : 0);
}

static t_eshape	ft_identifiy_tet(char *tmp)
{
	int count;
	int i;
	int j;

	i = 0;
	j = -1;
	count = 0;
	while (tmp[i])
	{
		if (tmp[i] == '#' && j == -1)
			j = 1;
		if (tmp[i] == '#')
			count = count + j;
		if (j != -1)
			j *= 2;
		i++;
		if (tmp[i] == '\n')
			i++;
	}
	return (ft_isvalidshape(count, 0) ? count : 0);
}

t_tet			*ft_filltab(char *file)
{
	t_tet	*tab;
	int		nb_tet;
	int		i;
	char	*tmp;

	nb_tet = count_tet(file);
	if (!(tab = malloc((nb_tet + 1) * sizeof(t_tet))))
		return (NULL);
	i = 0;
	while (i < nb_tet)
	{
		tmp = ft_strsub(file, i * 21, 20);
		if (!(tab[i].shape = ft_identifiy_tet(tmp)))
		{
			return (NULL);
		}
		tab[i].x = -1;
		tab[i].letter = 'A' + i;
		free(tmp);
		i++;
	}
	tab[nb_tet].shape = 0;
	return (tab);
}
