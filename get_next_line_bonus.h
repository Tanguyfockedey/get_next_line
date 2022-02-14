/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:58:19 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/11 13:58:19 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str, int eol);
size_t	ft_findeol(char *str);
char	*ft_readfromfd(char *bufjoin, int fd);
char	*ft_getline(char *str);
char	*ft_getendline(char *str);

#endif