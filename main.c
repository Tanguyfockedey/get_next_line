/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:42 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/14 21:29:14 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd[5];
	int		i = 3;
	int		j = 4;
	char	*buf;
	char	c = '0';
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

// GNL TEST
	fd[0] = open("myfile0.txt", O_RDONLY);
	fd[1] = open("myfile1.txt", O_RDONLY);
	fd[2] = open("myfile2.txt", O_RDONLY);
	fd[3] = open("myfile3.txt", O_RDONLY);
	fd[4] = open("myfile4.txt", O_RDONLY);

	printf("Press ENTER to get next line\n");
	while (j--) //getchar() == 10
	{
		buf = get_next_line(fd[i]);
		printf("fd %d | %s\n", i, buf);
		read(fd[i], &c, 1);
		printf("%c\n", c);
		free(buf);
		// i++;
		if (i == 5)
			i = 0;
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	return (0);
}