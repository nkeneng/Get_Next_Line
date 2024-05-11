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

int	ft_strchr(char *str, int len, int c)
{
	int	incr;

	incr = 0;
	while (incr < len)
	{
		if (str[incr] == (char)c)
			return (incr);
		incr++;
	}
	if (str[incr] == (char)c)
		return (incr);
	return (-1);
}

size_t	ft_strlen(char const *str)
{
	size_t	incr;

	incr = 0;
	while (str[incr])
		incr++;
	return (incr);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2, int max)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + max + 2));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j <= max)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
