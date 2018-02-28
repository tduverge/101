/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 18:30:54 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/15 18:30:58 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int		change_24_12(int hour)
{
	if (hour <= 12 && hour != 0 && hour != 24)
		return (hour);
	else if (hour == 0 || hour == 24)
		return (12);
	else if (hour >= 13)
		return (hour - 12);
	return (0);
}

void	ft_takes_place(int hour)
{
	ft_putstr("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour < 12 || hour == 24)
	{
		ft_putnbr(change_24_12(hour));
		ft_putstr(".00 A.M. AND ");
	}
	else
	{
		ft_putnbr(change_24_12(hour));
		ft_putstr(".00 P.M. AND ");
	}
	if (hour + 1 < 12 || hour + 1 == 24)
	{
		ft_putnbr(change_24_12(hour + 1));
		ft_putstr(".00 A.M\n");
	}
	else
	{
		ft_putnbr(change_24_12(hour + 1));
		ft_putstr(".00 P.M.\n");
	}
}
