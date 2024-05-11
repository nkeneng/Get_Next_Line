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

static int	parse_static(char **str, char **line)
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

static char	*free_return(char *line, char *buf, char *sv, int rn)
{
	free(buf);
	if (rn)
	{
		free(line);
		if (*sv)
			free(sv);
		return (NULL);
	}
	return (line);
}

static char	*logic(char **line, char **sv, char **buf, int fd)
{
	int	rr;
	int	rlp;

	while (1)
	{
		if (*sv && parse_static(sv, line))
			return (free_return(*line, *buf, *sv, 0));
		rr = read(fd, *buf, BUFFER_SIZE);
		if (rr <= 0)
			return (free_return(*line, *buf, *sv, 1));
		rlp = ft_strchr(*buf, '\n');
		if (rlp != -1)
		{
			*sv = ft_strdup(*buf + rlp + 1);
			return (free_return(ft_strjoin(*line, *buf, rlp), *buf, *sv, 0));
		}
		else
			*line = ft_strjoin(*line, *buf, ft_strlen(*buf));
	}
}

/*
*rlp = return line position
*
*/
char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*sv;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE);
	line = ft_strdup("");
	if (!buf && !line)
		return (NULL);
	return (logic(&line, &sv, &buf, fd));
}
