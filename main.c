/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:26:07 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/10 15:45:50 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// int		fd = open("test", O_RDONLY);
	// char	*line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// return (0);
	////////////////
	int		fd = open("test", O_RDONLY);
	char	*line = get_next_line(fd);
	for (; line != NULL; line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}