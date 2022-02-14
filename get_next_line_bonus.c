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

#include "get_next_line_bonus.h"

size_t	ft_findeol(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bufjoin[4096];

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE < 1)
		return (0);
	if (!ft_findeol(bufjoin[fd]))
		bufjoin[fd] = ft_readfromfd(bufjoin[fd], fd);
	if (!bufjoin[fd])
		return (0);
	line = ft_getline(bufjoin[fd]);
	bufjoin[fd] = ft_getendline(bufjoin[fd]);
	return (line);
}
