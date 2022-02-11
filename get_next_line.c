/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:08:04 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/11 13:56:51 by tfockede         ###   ########.fr       */
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
	static char	*bufjoin;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!ft_findeol(bufjoin))
		bufjoin = ft_readfromfd(bufjoin, fd); //malloc
	if (!bufjoin)
		return (0);
	line = ft_getline(bufjoin); //malloc
	bufjoin = ft_getendline(bufjoin);
	return (line);
}
