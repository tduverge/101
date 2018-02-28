/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:05:04 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/17 14:09:17 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] = str[i] + 'a' - 'A';
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int test;

	ft_strlowcase(str);
	i = 0;
	test = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a') && (str[i] <= 'z') && test)
		{
			str[i] = str[i] + 'A' - 'a';
		}
		i++;
		if (((str[i - 1] >= 'a') && (str[i - 1] <= 'z')) ||
				((str[i - 1] >= 'A') && (str[i - 1] <= 'Z')) ||
					((str[i - 1] >= '0') && (str[i - 1] <= '9')))
			test = 0;
		else
			test = 1;
	}
	return (str);
}
