/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parcing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 18:33:09 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:39:20 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fdf.h"

static int		count_space(char *s)
{
	int		i;
	int		nb_space;

	i = 0;
	nb_space = 0;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
			nb_space++;
		i++;
	}
	if (s[0] == ' ')
		nb_space--;
	if (s[i - 1] == ' ')
		nb_space--;
	return (nb_space + 1);
}

static int		*map_size(int fd)
{
	int		x;
	int		y;
	int		get_ret;
	int		*ret;
	char	*line;

	y = 0;
	while ((get_ret = get_next_line(fd, &line)))
	{
		if (y == 0)
			x = count_space(line);
		else if (x != count_space(line))
			return (NULL);
		free(line);
		y++;
	}
	close(fd);
	if (!(ret = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	ret[0] = x;
	ret[1] = y;
	return (ret);
}

static int		fill_tab(int **ret, int fd, int **size)
{
	int		ret_get;
	char	**str_tab;
	char	*line;
	int		x;
	int		y;

	y = 0;
	while ((ret_get = get_next_line(fd, &line)))
	{
		if (ret_get == -1 || !(str_tab = ft_strsplit(line, ' ')))
			return (0);
		x = 0;
		while (x < (*size)[0])
		{
			ret[y][x] = ft_atoi(str_tab[x]);
			free(str_tab[x]);
			x++;
		}
		free(str_tab);
		free(line);
		y++;
	}
	return (1);
}

int				**parsing(char *argv, int **size)
{
	int		**ret;
	int		i;
	int		fd;

	if (ft_strcmp(argv + (int)(ft_strlen(argv) - 4), ".fdf"))
		return (NULL);
	if ((fd = open(argv, O_RDONLY) == -1))
		return (NULL);
	if (!(*size = map_size(open(argv, O_RDONLY))))
		return (NULL);
	if (!(ret = (int**)malloc(sizeof(int*) * (*size)[1])))
		return (NULL);
	i = 0;
	while (i < (*size)[1])
	{
		if (!(ret[i] = (int*)malloc(sizeof(int) * (*size)[0])))
			return (NULL);
		i++;
	}
	if (!(fill_tab(ret, open(argv, O_RDONLY), size)))
		return (NULL);
	return (ret);
}
