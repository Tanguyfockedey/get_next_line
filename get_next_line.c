/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:08:04 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/08 17:18:37 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*bufjoin;
	int			eol_eof;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	buf[BUFFER_SIZE] = '\0';

	eol_eof = 1;
	while (eol_eof >= 0)
	{
		eol_eof = read(fd, buf, BUFFER_SIZE);
		bufjoin = ft_bufjoin(bufjoin, buf);
		if (ft_strlen(buf, 1) != BUFFER_SIZE)
			break ;
	}
	line = ft_getline(&bufjoin);
	printf("eol_eof = %d\n", eol_eof);
	
	free(buf);
	return (line);
}

/*get_next_line	
	protect
	copy memory into str
	while not eol eof
		read into buffer
		copy buffer into str  =>if eol or eof flag
	
	if eol
		keep remaining in memory
	if eof
		null
		


*/