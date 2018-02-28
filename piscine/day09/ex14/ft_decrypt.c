#include "ft_perso.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int nb;

	neg = 1;
	nb = 0;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * neg);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	str++;
	while (str[i] != ';' && str[i])
		i++;
	return (i);
}

int		*count_elem(char *str, int j)
{
	int		i;
	int		*tab;

	i = 0;
	while(str[j])
	{
		if (str[j] == '|')
			i++;
		j++;
	}
	tab = malloc(sizeof(int) * (i * 2 + 1));
	tab[0] = i;
	i = 1;
	while(*str)
	{
		tab[i++] = ft_atoi(str);
		while (*str != '|')
			str++;
		tab[i++] = ft_strlen(str);
		while (*str != ';' && *str)
			str++;
		str++;
	}
	return (tab);
}

char	*position_next_word(char *str)
{
	while (*str != '|')
		str++;
	str++;
	return (str);
}

t_perso		 **ft_decrypt(char *str)
{
	t_perso	**tab;
	int		*tab_elem;
	int		i;
	int		j;

	i = 0;
	tab_elem = count_elem(str, 0);
	tab = malloc(sizeof(t_perso*) * (tab_elem[0] + 1));
	while (*str)
	{
		j = -1;
		tab[i]->age = tab_elem[(i + 1) * 2 - 1];
		tab[i]->name = malloc(sizeof(char) * (tab_elem[(i + 1) * 2]));
		str = position_next_word(str);
		while (*str != ';' || *str)
			tab[i]->name[j++] = *str;
		tab[i]->name[j] = '\0';
		str++;
		i++;
	}
	return (tab);
}

int main()
{
	char str[] = "25|Bernard;36|Monique";
	t_perso **tab = ft_decrypt(str);
	(void)tab;
	return (0);
}
