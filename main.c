/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:42 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/02 22:07:41 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUFFER_SIZE 42

int	main(void)
{
	int fd;
	char	*buf;

	fd = open("myfile.txt", O_RDONLY);
	if (fd >= 0)
	{
		buf = get_next_line(fd);
		printf("%s", buf);

	}
	close(fd);
	return (0);
}