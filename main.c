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
	printf("buffer size  is %d\n", BUFFER_SIZE);
	int fd3 = open("41_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	return (0);
}

