/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:36:36 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/11 12:38:32 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(char *str, int len, int c)
{
	int	incr;

	incr = 0;
	while (str && str[incr] && incr < len)
	{
		if (str[incr] == (char)c)
			return (incr);
		incr++;
	}
	if (str[incr] && str[incr] == (char)c)
		return (incr);
	return (-1);
}

size_t	gnl_strlen(char const *str)
{
	size_t	incr;

	incr = 0;
	if (str)
	{
		while (str[incr])
			incr++;
	}
	return (incr);
}

char	*gnl_strjoin(char *s1, char *s2, int max)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (gnl_strlen(s1) + max + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j < max)
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	gnl_bzero(void *s, size_t n)
{
	size_t	incr;

	incr = 0;
	while (incr < n)
	{
		*(char *)s = '\0';
		s++;
		incr++;
	}
}
