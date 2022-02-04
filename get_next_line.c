/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:08:04 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/04 19:27:24 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a line read from a file descriptor
*/

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int 		eol_eof;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	eol_eof = 1;	
	while (eol_eof > 0)
	eol_eof = read(fd, buf, BUFFER_SIZE);
	printf("len = %d\n", eol_eof);
	buf[BUFFER_SIZE] = '\0';
	return (buf);
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