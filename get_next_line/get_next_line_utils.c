/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:39:27 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 11:10:39 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	i = -1;
	if (!s)
		return (NULL);
	if (!len)
		return (NULL);
	if (start >= ft_sstrlen(s))
		return (ft_strdup(""));
	if (len > ft_sstrlen(s))
		len = ft_sstrlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (++i < len)
		p[i] = s[start++];
	p[i] = '\0';
	return (p);
}

size_t	ft_sstrlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	ssize_t	lens1;
	ssize_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_sstrlen(s1);
	lens2 = ft_sstrlen(s2);
	p = malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!p)
		return (NULL);
	p[0] = '\0';
	ft_strlcat(p, s1, lens1 + 1);
	ft_strlcat(p, s2, lens1 + lens2 + 1);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	str = (char *) malloc (sizeof(char) * ft_sstrlen(s1) +1);
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}

int	ft_strchr( char *s1, int c)
{
	int	i;

	if (!s1)
		return (-1);
	i = 0;
	while (*(s1 + i))
	{
		if (s1[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
