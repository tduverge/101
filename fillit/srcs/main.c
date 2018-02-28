/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:33:31 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char	*file;
	t_tet	*tab;
	int		*sol;
	char	**soluce;

	if (argc != 2)
	{
		return (0);
	}
	file = recup_strfile(argv[1]);
	if (verif_file(file) == 0)
		return (0);
	if (!(tab = ft_filltab(file)))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(sol = (int *)ft_memalloc(sizeof(int) * 13)))
		return (0);
	ft_resolve(tab, ft_next_sqrt(count_tet(file) * 4) - 1,
			sol, count_tet(file));
	soluce = print_soluce(tab);
	ft_write2d(soluce);
}
