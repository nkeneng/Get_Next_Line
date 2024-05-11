/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:35:50 by snkeneng          #+#    #+#             */
/*   Updated: 2024/05/11 12:36:14 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_next_line2(int fd);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, int max);
int		ft_strchr(char *str, int len, int c);
size_t	ft_strlen(char const *str);

#endif
