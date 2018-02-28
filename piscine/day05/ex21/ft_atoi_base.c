/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:14:15 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/14 14:26:07 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		test_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		test_str(char *str, char *base)
{
	int i;
	int j;
	int ok;

	if (str[0] == '\0' || str[1] == '+' || str[1] == '-')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		ok = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j] || str[i] == '+' || str[i] == '-')
				ok = 1;
			j++;
		}
		if (ok == 0)
			return (0);
		i++;
	}
	return (1);
}

int		my_power(int nb, int power)
{
	int res;

	res = 0;
	if (power > 1)
	{
		res = my_power(nb, power - 1) * nb;
		return (res);
	}
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	return (0);
}

int		ft_atoi_base_calc(int base_len, int str_len, char *str, char *base)
{
	int neg;
	int nb;
	int index[2];

	neg = 1;
	nb = 0;
	index[0] = 0;
	if (str[index[0]] == '-' || str[index[0]] == '+')
	{
		if (str[index[0]] == '-')
			neg = -1;
		index[0]++;
	}
	while (index[0] < str_len)
	{
		index[1] = 0;
		while (str[index[0]] != base[index[1]])
			index[1]++;
		nb = index[1] * my_power(base_len, str_len - 1 - index[0]) + nb;
		index[0]++;
	}
	return (nb * neg);
}

int		ft_atoi_base(char *str, char *base)
{
	int base_len;
	int str_len;

	base_len = 1;
	while (base[base_len] != '\0')
		base_len++;
	if (test_base(base) == 0)
		return (0);
	str_len = 1;
	while (str[str_len] != '\0')
		str_len++;
	if (test_str(str, base) == 0)
		return (0);
	return (ft_atoi_base_calc(base_len, str_len, str, base));
}
