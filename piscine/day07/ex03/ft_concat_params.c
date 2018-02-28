/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:28:23 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/21 22:10:32 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_concat(char *concat, char *s1)
{
	int		s1_len;
	int		i;
	int		concat_len;

	s1_len = 0;
	concat_len = 0;
	while (concat[concat_len] != '\0')
		concat_len++;
	while (s1[s1_len] != '\0')
		s1_len++;
	concat[concat_len] = '\n';
	i = 0;
	while (i <= s1_len)
	{
		concat[i + concat_len + 1] = s1[i];
		i++;
	}
	return (concat);
}

int		ft_len_argv(int argc, char **argv)
{
	int len;
	int i;
	int j;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	char	*concat;
	int		len;

	if (argc <= 1)
		return ("");
	i = 0;
	len = ft_len_argv(argc, argv);
	concat = (char*)malloc(sizeof(char) * len);
	while (argv[1][i])
	{
		concat[i] = argv[1][i];
		i++;
	}
	concat[i] = '\0';
	i = 2;
	while (i <= argc - 1)
	{
		concat = ft_concat(concat, argv[i]);
		i++;
	}
	return (concat);
}
