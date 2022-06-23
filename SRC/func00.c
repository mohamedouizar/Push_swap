/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:17:09 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/05 04:15:16 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	ft_isdigit(int c)
{
	return (!(c < '0' || c > '9'));
}

long	ft_atoi(const char *str)
{
	unsigned long	res;
	int				i;
	int				signe;

	signe = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
			res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * signe);
}

int	ft_s_digit(char	*str)
{
	int	i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}
