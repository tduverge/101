/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:53:11 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/13 20:42:45 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	writer(int *tab)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putchar(tab[i] + '1');
		i++;
	}
	ft_putchar('\n');
}

int		test(int *tab, int ligne, int colonne)
{
	int i;

	i = 0;
	while (i < colonne)
	{
		if (ligne == tab[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < colonne)
	{
		if ((tab[i] == ligne - (colonne - i))
				|| (tab[i] == ligne + (colonne - i)))
			return (0);
		i++;
	}
	return (1);
}

void	recursive_fct(int *tab, int *nb, int colonne)
{
	int ligne;

	ligne = 0;
	while (ligne < 8)
	{
		if ((test(tab, ligne, colonne) == 1) && (colonne != 7))
		{
			tab[colonne] = ligne;
			recursive_fct(tab, nb, colonne + 1);
			tab[colonne] = -1;
		}
		else if (test(tab, ligne, colonne) == 1)
		{
			tab[colonne] = ligne;
			writer(tab);
			*nb = *nb + 1;
			tab[colonne] = -1;
		}
		ligne++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int nb_solution;
	int tab[8];
	int i;

	i = 0;
	while (i < 8)
	{
		tab[i] = -1;
		i++;
	}
	nb_solution = 0;
	recursive_fct(tab, &nb_solution, 0);
}
