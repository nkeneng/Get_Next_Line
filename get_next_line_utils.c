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

size_t	ft_strlen(char const *str)
{
	size_t	incr;

	incr = 0;
	while (str && str[incr])
		incr++;
	return (incr);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = malloc(len + 1);
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
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j <= max)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	incr;
	char	*dest2;

	if (!dest && !src)
		return (dest);
	incr = 0;
	dest2 = dest;
	if (dest2 < (char *)src)
	{
		while (incr < n)
		{
			*(char *)dest++ = *(char *)src++;
			incr++;
		}
	}
	else
	{
		while (incr < n)
		{
			*(char *)(dest + n - 1) = *(char *)(src + n - 1);
			n--;
		}
	}
	return (dest2);
}
