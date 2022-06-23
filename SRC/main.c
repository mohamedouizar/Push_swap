/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:03:58 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/23 07:33:22 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ifupdown(int	tab, t_list **stack)
{
	int	mid = 6 / 2;
	int	cmp;
//	int	cmp2;

	cmp = 0;
	printf("lstsize is %d\n",mid);
	while (cmp < 6 )
	{
		if (tab == (*stack)->content)
			break;
		cmp++;
		(*stack) = (*stack)->next;
	}
	if (cmp <= mid)
	{
		printf("up");
		return 0;
	}
	if (cmp >= mid)
	{
		
		printf("down");
		return 1;
	}
	return (cmp + 1);
}

int	main(int ac, char **av)
{
	t_list	*stack = NULL;
	int		*tab;
	int		index;
	t_list	*stackb = NULL;

	index = 0;
	if (ac > 1)
	{
		ft_check_av(ac, av);
		add_av_tostack(av, ac, &stack);
		check_sorted(stack);
		tab = convert_ls_to_array(stack);
		sorting(&stack, &stackb, tab);
		while (stack)
		{
			printf("\n|stack a|\t%d\n", stack->content);
			stack = stack->next;
		}
		// printf("\n\n\n");
		// while (stackb)
		// {
		// 	printf("\n|stack b|\t%d", stackb->content);
		// 	stackb = stackb->next;
		// }

		//printf("%d\n", check_ifupdown(20, &stack));
		// printf("\ncmp is %d\n",ft_lstsize(stackb));
			//printf("%d sorted|%d|\n", index, tab[index]);
	// while (index < ft_lstsize(stack))
	// 	{
	// 		printf("%d sorted|%d|\n", index, tab[index]);
	// 		index++;
	// 	}
	}
}
