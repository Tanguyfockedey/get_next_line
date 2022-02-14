/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:20:21 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/14 21:36:40 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str, int eol);
size_t	ft_findeol(char *str);
char	*ft_readfromfd(char *bufjoin, int fd);
char	*ft_getline(char *str);
char	*ft_getendline(char *str);

#endif