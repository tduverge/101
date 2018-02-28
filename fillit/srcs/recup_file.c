/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recup_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:31 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 11:02:48 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"
#include "../header/libft.h"

char	*recup_strfile(char *name_file)
{
	char	*buf;
	int		len;

	if (!(buf = (char *)malloc(sizeof(char) * BUF_SIZE)))
		return (NULL);
	len = read(open(name_file, O_RDONLY), buf, BUF_SIZE);
	free(buf);
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	read(open(name_file, O_RDONLY), buf, len);
	buf[len] = '\0';
	return (buf);
}
