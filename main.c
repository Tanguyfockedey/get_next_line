/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:42 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/08 17:33:56 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buf;
	printf("\nBuffer size = %d\n", BUFFER_SIZE);

//BUFJOIN TEST
	// char	*s1 = 0;
	// char	s2[] = "abc";	
	// s1 = ft_bufjoin(s1, s2);
	// printf("bufjoin = %s\n", s1);
	// s1 = ft_bufjoin(s1, s2);
	// printf("bufjoin = %s\n", s1);
	// free(s1);

// STRLEN TEST
	// char s1[] = "123\n\nabc";
	// printf("s1 = %s\n", s1);
	// printf("strlen 0 = %ld\n", ft_strlen(s1, 0));
	// printf("strlen 1 = %ld\n", ft_strlen(s1, 1));

	fd = open("myfile.txt", O_RDONLY);

	while (getchar() == '\n')
	{
		buf = get_next_line(fd);
		printf("%s\n", buf);
		free(buf);
	}
	close(fd);
	return (0);
}