/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:05:04 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/18 15:59:40 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(((str[i] >= 'a') && (str[i] <= 'z')) ||
				((str[i] >= 'A') && (str[i] <= 'Z'))))
			return (0);
		i++;
	}
	return (1);
}
