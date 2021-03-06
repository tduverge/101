/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 19:06:28 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int		not_format(t_list **pile, char *arg)
{
	if (not_numeric(pile, arg))
		return (1);
	if (got_doubles(pile))
		return (1);
	return (0);
}

static int		ex_prg(int err, t_list **a, t_list **b)
{
	ft_lstdel(a, ft_del);
	ft_lstdel(b, ft_del);
	if (!err)
		return (0);
	else
		ft_putstr_fd("Error\n", 2);
	return (-1);
}

void			choose_sort(t_list **a, t_list **b, int len)
{
	if (len <= 3)
		simple_sort(a, b, len);
	else if (len <= 5)
		insertion_sort(a, b);
	else if (len <= 300)
		genius_insert(a, b);
	else
		quicksort(a, b);
}

int				main(int ac, char **av)
{
	int		i;
	int		len;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (ex_prg(0, &a, &b));
	i = ac - 1;
	while (i >= 1)
		if (not_format(&a, av[i--]))
			return (ex_prg(1, &a, &b));
	if (ft_lstis_sorted(a))
		return (ex_prg(0, &a, &b));
	len = ft_lstlen(a);
	change_to_index(a);
	choose_sort(&a, &b, len);
	return (ex_prg(0, &a, &b));
}
