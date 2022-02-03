/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:42 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/03 15:32:49 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char	*buf;

	printf("Buffer size = %d\n", BUFFER_SIZE);
	fd = open("myfile.txt", O_RDONLY);
	if (fd > -1)
	{
		buf = get_next_line(fd);
		printf("%s", buf);

	}
	close(fd);
	return (0);
}