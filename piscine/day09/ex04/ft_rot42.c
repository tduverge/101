/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:38:03 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/16 11:39:39 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = 'a' + (str[i] - 'a' + 42) % 26;
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = 'A' + (str[i] - 'A' + 42) % 26;
		i++;
	}
	return (str);
}
