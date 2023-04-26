/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:07:57 by tafocked          #+#    #+#             */
/*   Updated: 2023/04/21 16:07:59 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"

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
	static char	*bufjoin;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!ft_findeol(bufjoin))
		bufjoin = ft_readfromfd(bufjoin, fd);
	if (!bufjoin)
		return (0);
	line = ft_getline(bufjoin);
	bufjoin = ft_getendline(bufjoin);
	return (line);
}
