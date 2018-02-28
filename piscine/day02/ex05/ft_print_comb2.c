/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:19:35 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/10 21:00:59 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb < 10)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
	}
}

void	writer(int first_nb, int second_nb)
{
	if (first_nb < 10)
		ft_putchar('0');
	ft_putnbr(first_nb);
	ft_putchar(' ');
	if (second_nb < 10)
		ft_putchar('0');
	ft_putnbr(second_nb);
	if ((first_nb != 98) || (second_nb != 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int first_nb;
	int second_nb;

	first_nb = 0;
	second_nb = 1;
	while (first_nb <= 98)
	{
		while (second_nb <= 99)
		{
			writer(first_nb, second_nb);
			second_nb++;
		}
		first_nb++;
		second_nb = first_nb + 1;
	}
}
