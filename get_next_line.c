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

static int	parse_static(char **sv, char **line)
{
	int	rlp;

	rlp = ft_strchr(*sv, ft_strlen(*sv), '\n');
	if (rlp != -1)
	{
		*line = ft_strjoin(*line, *sv, rlp);
		ft_memmove(*sv, *sv + rlp + 1, ft_strlen(*sv - rlp));
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

static int	logic(char **line, char **sv, char **buf, int fd)
{
	int	rr;
	int	rlp;

	while (1)
	{
		if (*sv && parse_static(sv, line))
			return (0);
		rr = read(fd, *buf, BUFFER_SIZE);
		if (rr < 0 || (rr == 0 && line == NULL))
			return (1);
		if (rr == 0)
			return (2);
		rlp = ft_strchr(*buf, rr, '\n');
		if (rlp != -1)
		{
			*sv = ft_strdup(*buf + rlp + 1);
			if (!*sv)
				return (1);
			*line = ft_strjoin(*line, *buf, rlp);
			return (0);
		}
		else
		{
			if (*sv)
			{
				*line = ft_strjoin(*line, *sv, ft_strlen(*sv));
				free(*sv);
				*sv = NULL;
			}
			*line = ft_strjoin(*line, *buf, ft_strlen(*buf));
		}
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
	int			res;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (!buf || fd < 0)
		return (free_return(line, buf, sv, 1));
	ft_bzero(buf, BUFFER_SIZE + 1);
	res = logic(&line, &sv, &buf, fd);
	return (free_return(line, buf, sv, res));
}
