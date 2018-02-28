/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:18:53 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/17 21:43:13 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		match(char *s1, char *s2)
{
	if (ft_strcmp(s1, s2) == 0 || ft_strcmp(s2, "*") == 0)
		return (1);
	if (ft_strlen(s2) == 0 || ft_strlen(s1) == 0)
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == '*' && *s2 == '*')
			s1++;
		else
		{
			s1++;
			s2++;
		}
	}
	while (*s2 == '*' && (*(s2 + 1) == '*'))
		s2++;
	if (*s1 == '\0' && *s2 == '*')
		return (match(s1, s2 + 1));
	if (*s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	return (0);
}
