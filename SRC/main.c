/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:03:58 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/26 19:33:20 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ifupdown(int tab, t_list *stack)
{
	int	mid;
	int	count;

	mid = ft_lstsize(stack) / 2 ;
	count = 1;
	while (stack)
	{
		if (stack->content == tab)
			break ;
		count++;
		stack = stack->next;
	}
	if (count >= mid)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack;
	int		*tab;
	int		index;
	t_list	*stackb;

	stackb = NULL;
	stack = NULL;
	index = 0;
	if (ac > 1)
	{
		ft_check_av(ac, av);
		add_av_tostack(av, ac, &stack);
		check_sorted(stack);
		tab = convert_ls_to_array(stack);
		sorting(&stack, &stackb, tab);
	}
}
