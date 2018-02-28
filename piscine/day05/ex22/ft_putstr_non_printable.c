/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:09:54 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/17 14:10:27 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		test(char *base, int base_len)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;

	base_len = 1;
	while (base[base_len] != '\0')
		base_len++;
	if (test(base, base_len) == 0)
		return ;
	if (nbr == -2147483648)
		ft_putnbr_base(nbr / base_len, base);
	if (nbr <= -1 && nbr != -2147483648)
		ft_putchar('-');
	if (nbr <= -1 && nbr != -2147483648)
		nbr = -nbr;
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len]);
	else
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
	if (nbr == -2147483648)
		ft_putchar(base[base_len - (nbr % base_len)]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] <= 15)
				ft_putchar('0');
			ft_putnbr_base(str[i], "0123456789abcdef");
		}
		i++;
	}
}
