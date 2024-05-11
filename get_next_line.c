/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:34:36 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/11 12:35:22 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	parse_static(char **str, char **line)
{
	int	rlp;

	rlp = ft_strchr(*str, '\n');
	if (rlp != -1)
	{
		*line = ft_strjoin(*line, *str, rlp);
		*str = *str + rlp + 1;
		return (1);
	}
	return (0);
}

char	*free_return(char *line, char *buf)
{
	free(buf);
	return (line);
}

/*
*rlp = return line position
*
*/
char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	ssize_t		rr;
	int			rlp;
	static char	*sv;

	buf = (char *)malloc(BUFFER_SIZE);
	line = ft_strdup("");
	while (1)
	{
		if (sv && parse_static(&sv, &line))
			return (free_return(line, buf));
		rr = read(fd, buf, BUFFER_SIZE);
		if (rr <= 0)
			return (NULL);
		rlp = ft_strchr(buf, '\n');
		if (rlp != -1)
		{
			sv = ft_strdup(buf + rlp + 1);
			line = ft_strjoin(line, buf, rlp);
			return (line);
		}
		else
			line = ft_strjoin(line, buf, ft_strlen(buf));
	}
}
