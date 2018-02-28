/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:46:59 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/12 22:30:31 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	writer(int n, int *tab, int sum_max)
{
	int index;
	int sum;

	index = 0;
	sum = 0;
	while (index < n)
	{
		ft_putchar(tab[index] + '0');
		sum = sum + tab[index];
		index++;
	}
	if (sum < sum_max)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int		calc_sum_max(int n, int *max)
{
	int i;
	int sum_max;

	i = 0;
	sum_max = 0;
	while (i < n)
	{
		max[i] = 10 - (n - i);
		sum_max = sum_max + max[i];
		i++;
	}
	return (sum_max);
}

void	ft_recursive(int n, int *tab, int *max, int nb_it)
{
	int index;
	int sum_max;

	sum_max = calc_sum_max(n, max);
	while (tab[nb_it] <= max[nb_it])
	{
		if (nb_it == n - 1)
		{
			writer(n, tab, sum_max);
		}
		else
			ft_recursive(n, tab, max, nb_it + 1);
		tab[nb_it]++;
		index = nb_it + 1;
		while (index < n)
		{
			tab[index] = tab[index - 1] + 1;
			index++;
		}
	}
}

void	ft_print_combn(int n)
{
	int i;
	int tab[n];
	int max[n];

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	ft_recursive(n, tab, max, 0);
}

void	ft_print_comb(void)
{
	ft_print_combn(3);
}
