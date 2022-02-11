/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:57:29 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/11 13:57:29 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bufjoin[1000];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!ft_findeol(bufjoin[fd]))
		bufjoin[fd] = ft_readfromfd(bufjoin[fd], fd); //malloc
	if (!bufjoin[fd])
		return (0);
	line = ft_getline(bufjoin[fd]); //malloc
	bufjoin[fd] = ft_getendline(bufjoin[fd]);
	return (line);
}
