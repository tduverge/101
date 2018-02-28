/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 23:34:45 by tduverge          #+#    #+#             */
/*   Updated: 2017/09/18 00:19:08 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	count_words(char *str, int *nb_words, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\t' ||
				str[*i] == '\n' || str[*i] == '\0'))
	{
		(*i)++;
	}
	*nb_words = *nb_words + 1;
	if (str[*i] != '\0')
		count_words(str, nb_words, i);
}

void	size_words(char *str, int *i, int *tablen_words, int nb_rec)
{
	int len_word;

	len_word = 0;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\t' ||
				str[*i] == '\n' || str[*i] == '\0'))
	{
		len_word++;
		(*i)++;
	}
	tablen_words[nb_rec] = len_word;
	if (str[*i] != '\0')
		size_words(str, i, tablen_words, nb_rec + 1);
}

void	words_in(char *str, char **res, int *i, int nb_rec)
{
	int j;

	j = 0;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\t' ||
				str[*i] == '\n' || str[*i] == '\0'))
	{
		res[nb_rec][j] = str[*i];
		(*i)++;
		j++;
	}
	res[nb_rec][j] = '\0';
	if (str[*i] != '\0')
		words_in(str, res, i, nb_rec + 1);
}

char	**ft_split_whitespaces(char *str)
{
	int		nb_words;
	int		*tablen_words;
	int		i;
	char	**res;

	nb_words = 0;
	i = 0;
	count_words(str, &nb_words, &i);
	if (!(tablen_words = (int*)malloc(sizeof(int) * (nb_words))))
		return (NULL);
	i = 0;
	size_words(str, &i, tablen_words, 0);
	if (!(res = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		if (!(res[i] = (char*)malloc(sizeof(char) * (tablen_words[i] + 1))))
			return (NULL);
		i++;
	}
	i = 0;
	words_in(str, res, &i, 0);
	res[nb_words] = 0;
	return (res);
}
