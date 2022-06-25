/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:34:05 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 15:26:46 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<fcntl.h> 
# include<errno.h>
# include<unistd.h>
# include<stdlib.h>
# define BUFFER_SIZE 100000

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_sstrlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize);
#endif