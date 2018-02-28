/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:17:44 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/17 21:52:57 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort_str(int argc, char **argv)
{
	int		i;
	int		i_max;
	char	*save;

	i_max = 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], argv[i_max]) > 0)
			i_max = i;
		i++;
	}
	save = argv[argc - 1];
	argv[argc - 1] = argv[i_max];
	argv[i_max] = save;
	if (argc >= 3)
		sort_str(argc - 1, argv);
}

int		main(int argc, char **argv)
{
	int i;

	sort_str(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
