/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:15 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 22:03:32 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
				exit(write(2, "Error\n", 6));
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
			exit(write(2, "Error\n", 6));
		if (ft_atoi(av[i]) < -2147483648)
			exit(write(2, "Error\n", 6));
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_empty_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		i++;
	}
	return (1);
}
