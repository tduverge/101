/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   verif_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:46 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:01:53 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"

static int	verif_valid(char *s, int i, int k)
{
	int		j;

	if (!(s[i]))
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i] == '#' || s[i] == '.')
		{
			j++;
			i++;
		}
		if (j != 4 || !(s[i] == '\n' || s[i] == '\0'))
			return (0);
		k++;
		if ((s[i + 1] != '.' && s[i + 1] != '#') || s[i] == '\0')
		{
			if (k != 4 || (s[i + 1] == '\n' && s[i + 2] == '\0'))
				return (0);
			k = 0;
		}
		if (s[i] == '\n')
			i += (s[i + 1] == '\n' ? 2 : 1);
	}
	return (1);
}

int			verif_file(char *s)
{
	int check;

	check = verif_valid(s, 0, 0);
	if (check == 0)
		ft_putstr("error\n");
	return (check);
}
