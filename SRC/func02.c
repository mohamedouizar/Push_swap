/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:22:30 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 22:05:49 by mouizar          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

	i = ac - 1;
	while (i > 0)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
		new->next = *lst;
		*lst = new;
}
