/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:41:59 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/16 11:42:01 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_comparestring(char *str, char *ref)
{
	while (*str != '\0')
	{
		if (*str == '\t' || *str == ' ')
			str++;
		else if (*str != *ref)
			return (0);
		else
		{
			ref++;
			str++;
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int alert;

	i = 0;
	alert = 0;
	while (i < argc)
	{
		if (ft_comparestring(argv[i], "president"))
			alert = 1;
		else if (ft_comparestring(argv[i], "kill"))
			alert = 1;
		else if (ft_comparestring(argv[i], "Bauer"))
			alert = 1;
		i++;
	}
	if (alert != 0)
		write(1, "Alert!!!\n", 9);
	return (0);
}
