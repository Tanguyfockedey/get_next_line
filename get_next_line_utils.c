/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:13:14 by tfockede          #+#    #+#             */
/*   Updated: 2022/02/08 14:13:14 by tfockede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int eol)
{
	size_t	i;

	i = 0;
	if (eol)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	else
		while (str[i] != '\0')
			i++;
	return (i);
}

char	*ft_bufjoin(char *s1, const char *s2)
{
	char	*string;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1;
	string = malloc(len * sizeof(char));
	if (!string)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		string[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		string[i + j] = s2[j];
	string[i + j] = '\0';
	free(s1);
	return (string);
}

char	*ft_getline(char **str)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = ft_strlen(*str, 1);
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (0);
	i = -1;
	while (++i <= len)
		line[i] = *str[i];
	line[len + 1] = '\0';

	return (line);
}