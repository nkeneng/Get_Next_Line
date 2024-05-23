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
#include <stdlib.h>

static int	parse_static(char **sv, char **line)
{
	int	rlp;
	int	incr;

	rlp = ft_strchr(*sv, ft_strlen(*sv), '\n');
	incr = 0;
	if (rlp != -1)
	{
		*line = ft_strjoin(*line, *sv, rlp);
		while (incr < (int)ft_strlen(*sv) - rlp)
		{
			(*sv)[incr] = (*sv)[incr + rlp + 1];
			incr++;
		}
		return (1);
	}
	return (0);
}

/*
 *
 * rn  = return null ?
 */
static char	*free_return(char *line, char *buf, char *sv, int rn)
{
	if (buf)
		free(buf);
	if (rn == 1)
	{
		if (line)
			free(line);
		if (sv)
		{
			free(sv);
			sv = NULL;
		}
		return (NULL);
	}
	else if (rn == 2 && sv)
	{
		free(sv);
		sv = NULL;
	}
	return (line);
}

int	handle_line_break(char **buf, char **line, char **sv, int rr)
{
	int	rlp;

	rlp = ft_strchr(*buf, rr, '\n');
	if (rlp != -1)
	{
		if (*(*buf + rlp + 1) != '\0')
			*sv = ft_strjoin(*sv, *buf + rlp + 1, ft_strlen(*buf + rlp + 1));
		if (**buf != '\0')
			*line = ft_strjoin(*line, *buf, rlp);
		return (0);
	}
	else
	{
		if (**buf != '\0')
		{
			*line = ft_strjoin(*line, *buf, ft_strlen(*buf));
			if (!*line)
				return (1);
		}
		ft_bzero(*buf, BUFFER_SIZE + 1);
		return (-1);
	}
}

static int	logic(char **line, char **sv, char **buf, int fd)
{
	int	rr;
	int	rlp;

	while (1)
	{
		if (*sv && parse_static(sv, line))
			return (0);
		if (*sv)
		{
			if (**sv != '\0')
				*line = ft_strjoin(*line, *sv, ft_strlen(*sv));
			free(*sv);
			*sv = NULL;
		}
		rr = read(fd, *buf, BUFFER_SIZE);
		if (rr < 0 || (rr == 0 && *line == NULL))
			return (1);
		if (rr == 0)
			return (2);
		rlp = handle_line_break(buf, line, sv, rr);
		if (rlp != -1)
			return (rlp);
	}
}

/*
*/
char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*sv;
	int			res;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (!buf || fd < 0)
		return (free_return(line, buf, sv, 1));
	ft_bzero(buf, BUFFER_SIZE + 1);
	res = logic(&line, &sv, &buf, fd);
	return (free_return(line, buf, sv, res));
}
