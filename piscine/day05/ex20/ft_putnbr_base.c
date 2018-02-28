/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:44:57 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/18 16:01:56 by tduverge         ###   ########.fr       */
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
	int		base_len;

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
