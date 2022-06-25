/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:42:52 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 11:11:07 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	if (dstsize == 0)
		return (ft_sstrlen(src));
	lendst = ft_sstrlen(dst);
	if (dstsize < lendst)
		return (dstsize + ft_sstrlen(src));
	while (src[i] && ((lendst + i) + 1) < dstsize)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + ft_sstrlen(src));
}

char	*ft_read_join(char *sstr, int fd1)
{
	char		*buff;
	int			nb;
	char		*tmp;

	nb = 1;
	buff = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strchr(sstr, '\n') == -1 && nb > 0)
	{
		nb = read (fd1, buff, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buff);
			return (NULL);
		}
		else
			buff[nb] = '\0';
		tmp = sstr;
		sstr = ft_strjoin(sstr, buff);
		free(tmp);
	}
	free(buff);
	return (sstr);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*return_line;
	char		*tmp2;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = ft_read_join(static_str, fd);
	if (!static_str)
		return (NULL);
	index = 0;
	while (static_str[index] != '\0' && static_str[index] != '\n')
		index++;
	return_line = ft_substr(static_str, 0, index + 1);
	tmp2 = static_str;
	static_str = ft_substr(static_str, index + 1, ft_sstrlen(static_str));
	free(tmp2);
	if (return_line[0] == '\0')
	{
		free(return_line);
		free(static_str);
		return (NULL);
	}
	return (return_line);
}
