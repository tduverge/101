/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 23:20:13 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/14 20:41:01 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	save;

	len = ft_strlen(str);
	i = 0;
	while (i <= (len - 1)/ 2)
	{
		save = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = save;
		i++;
	}
	return (str);
}
