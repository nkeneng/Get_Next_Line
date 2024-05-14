/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:48:29 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/11 11:48:34 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	printf("buffer size  is %d\n", BUFFER_SIZE);
	int fd3 = open("files/multiple_line_no_nl", O_RDONLY);
	line =  get_next_line(fd3);
	printf("%s", line);
	line =  get_next_line(fd3);
	printf("%s", line);
	close(fd3);
	free(line);
	return (0);
}

