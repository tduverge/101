/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:18:44 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 09:57:13 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 10
# define ERROR(x) if (!(x)) return (-1)

int						get_next_line(const int fd, char **line);

typedef struct			s_lastbuf
{
	int					fd;
	char				*lastbuf;
	struct s_lastbuf	*next;
}						t_lastbuf;

#endif
