/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:26:07 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/12 22:11:20 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		fd = open("test", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 2
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 3
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 4
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 5
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 6
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 7
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	line = get_next_line(fd); // 8
	printf("%s", line);
	// printf("(%p)", line);
	free(line);
	return (0);
	//////////////
	// int		i = 0;
	// int		fd = open("test", O_RDONLY);
	// for (char *line = get_next_line(fd); line; line = get_next_line(fd))
	// {
	// 	printf("%s", line);
	// 	i++;
	// 	printf("(%d)", i);
	// }
	// return (0);
}