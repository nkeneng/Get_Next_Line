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
	if (str)
	{
		while (str[incr])
			incr++;
	}
	return (incr);
}

char	*ft_strjoin(char *s1, char *s2, int max)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + max + 1));
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

/*
t_list	*handle_list(t_list **lst, void *content, int action)
{
	t_list	*element;
	t_list	*last;

	if (action == 1)
	{
		element = malloc(sizeof(t_list));
		if (!element)
			return (NULL);
		element->content = content;
		element->next = NULL;
		while (last->next)
			last = last->next;
		last-
		return (element);
	}
	else if (action == 2)
	{
		free(lst->content);
		free(lst);
	}
}
*/
