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
	char *line2;
	char *line3;
	printf("buffer size  is %d\n", BUFFER_SIZE);
	int fd3 = open("files/multiple_line_no_nl", O_RDONLY);
	line =  get_next_line(fd3);
	printf("%s", line);
	free(line);
	line2 =  get_next_line(fd3);
	printf("%s", line2);
	free(line2);
	line3 =  get_next_line(fd3);
	printf("%s", line3);
	free(line3);

	close(fd3);
	return (0);
}

