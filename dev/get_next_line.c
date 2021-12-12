/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:39:09 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/12 22:10:36 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*next_run(char *store)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	rtn = malloc(ft_strlen(store) + 1);
	if (rtn == NULL)
		return (NULL);
	i++;
	while (store[i])
		rtn[j++] = store[i++];
	rtn[j] = '\0';
	free(store);
	// printf("DEBUGnr(%s)", rtn);
	return (rtn);
}

char	*read_from_fd(int fd, char *store)
{
	char	*buf;
	ssize_t	b_read;

	b_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (b_read != 0 && !(ft_strchr(store, '\n')))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[b_read] = '\0';
		store = ft_strjoin(store, buf);
	}
	free(buf);
	// printf("DEBUGrff(%s)", store);
	return (store);
}

char	*line_to_rtn(char *store)
{
	char	*rtn;
	int		i;

	if (store[0] == '\0')
		return (NULL);
	i = -1;
	rtn = malloc(ft_strlen(store) + 1);
	if (!rtn)
		return (NULL);
	while (store[++i] != '\0' && store[i] != '\n')
		rtn[i] = store[i];
	if (store[i] == '\n')
	{
		rtn[i] = '\n';
		rtn[i + 1] = '\0';
		// printf("DEBUGltr(%s)", rtn);
		return (rtn);
	}
	rtn[i] = '\0';
	// printf("DEBUGltr(%s)", rtn);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_from_fd(fd, store);
	if (store == NULL)
		return (NULL);
	rtn = line_to_rtn(store);
	store = next_run(store);
	return (rtn);
}
