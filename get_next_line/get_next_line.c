/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_next_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 08:11:56 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 15:50:02 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int		no_read(char **line, char **lastbuf, char *next)
{
	char	*tmp;

	ERROR(*line = ft_strsub(*lastbuf, 0, next - *lastbuf));
	tmp = *lastbuf;
	ERROR(*lastbuf = ft_strdup(next + 1));
	free(tmp);
	return (1);
}

static int		fd_next_line(int fd, char **line, char **lastbuf)
{
	char	*next;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	if ((next = ft_strchr(*lastbuf, '\n')))
		return (no_read(line, lastbuf, next));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = *lastbuf;
		ERROR(*lastbuf = ft_strjoin(*lastbuf, buf));
		free(tmp);
		if (ft_strchr(buf, '\n'))
			return (fd_next_line(fd, line, lastbuf));
		*line = *lastbuf;
		i = 1;
	}
	if (ret == -1)
		return (-1);
	return (i ? i : ret);
}

int				get_next_line(int fd, char **line)
{
	static t_lastbuf	*lst;
	t_lastbuf			*cur;

	if (lst)
	{
		cur = lst;
		while (cur && cur->fd != fd)
		{
			cur = cur->next;
		}
		if (cur)
			return (fd_next_line(fd, line, &cur->lastbuf));
	}
	ERROR(cur = (t_lastbuf *)malloc(sizeof(t_lastbuf)));
	cur->fd = fd;
	if (lst)
		cur->next = lst;
	else
		cur->next = NULL;
	lst = cur;
	ERROR(cur->lastbuf = (char *)ft_memalloc(sizeof(char)));
	return (fd_next_line(fd, line, &cur->lastbuf));
}
