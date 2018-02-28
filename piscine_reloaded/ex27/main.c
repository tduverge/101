/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:37:43 by tduverge          #+#    #+#             */
/*   Updated: 2017/11/07 15:01:36 by tduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "proto.h"

int		main(int argc, char **argv)
{
	char res[4096];

	if (argc == 1)
		ft_putstr_error("File name missing.\n");
	else if (argc == 2)
	{
		res[read(open(argv[1], O_RDONLY), res, 4096)] = '\0';
		ft_putstr(res);
	}
	else
		ft_putstr_error("Too many arguments.\n");
}
