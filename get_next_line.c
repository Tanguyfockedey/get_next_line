/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:08:04 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/02 22:09:32 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"
#define BUFFER_SIZE 42

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buf, BUFFER_SIZE);
	return (buf);
}