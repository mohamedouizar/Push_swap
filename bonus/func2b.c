/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:14:51 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 22:25:42 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_av(int ac, char **av)
{
	ft_av_digit(ac, av);
	ft_av_dup(ac, av);
	ft_maxint(ac, av);
	ft_empty_av(ac, av);
	return (1);
}

void	check_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			break ;
	}
	if (!stack->next)
		exit(EXIT_FAILURE);
}

void	add_av_tostack(char	**av, int ac, t_list **stack)
{
	int		i;

	i = ac -1;
	while (i > 0)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
}

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
			exit(write(2, "Error\n", 6));
		i++;
	}
	return (1);
}
