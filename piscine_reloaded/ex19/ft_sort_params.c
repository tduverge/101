/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:13:53 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/07 13:23:36 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int n, char **argv)
{
	int		i;
	int		i_max;
	char	*swap;

	i = 1;
	i_max = 1;
	if (n <= 2)
		return ;
	while (i < n)
	{
		if (ft_strcmp(argv[i_max], argv[i]) < 0)
			i_max = i;
		i++;
	}
	swap = argv[n - 1];
	argv[n - 1] = argv[i_max];
	argv[i_max] = swap;
	ft_sort_params(n - 1, argv);
	return ;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		main(int argc, char **argv)
{
	int i;

	ft_sort_params(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
