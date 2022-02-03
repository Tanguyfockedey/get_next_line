/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:08:04 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/03 15:31:15 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buf, BUFFER_SIZE);
	return (buf);
}