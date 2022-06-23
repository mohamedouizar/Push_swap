/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:22:30 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/23 06:59:34 by mouizar          ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*sn1;
	unsigned char	*sn2 ;

	sn2 = (unsigned char *) s2;
	sn1 = (unsigned char *) s1;
	i = 0;
	while ((sn1[i] == sn2[i]) && sn1[i] && sn2[i])
		i++;
	return (sn1[i] - sn2[i]);
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

void	add_av_tostack(char	**av,int ac, t_list **stack)
{
	int		i;
		
	i = ac -1;
	while (i > 0)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_atoi(av[i])));
		i --;
	}
}
