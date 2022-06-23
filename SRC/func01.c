/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:58:04 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/05 04:11:57 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

int	ft_av_digit(int arc, char **arv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < arc)
	{
		if (!ft_s_digit(arv[i]))
		{
			printf("error digit");
			exit(1);
		}
		i++;
	}
	return (1);
}

int	ft_av_dup(int arc, char **arv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= arc)
	{
		j = i + 1;
		while (j < arc)
		{
			if (ft_strcmp(arv[i], arv[j]) == 0)
			{
				printf("duuup\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_maxint(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647)
		{
			ft_putstr_fd("ERROR max", 2);
			exit(1);
		}
		if (ft_atoi(av[i]) < -2147483648)
		{
			ft_putstr_fd("ERROR min", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	ft_empty_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr_fd("ERROR empty", 2);
			exit (1);
		}
		i++;
	}
	return (1);
}
