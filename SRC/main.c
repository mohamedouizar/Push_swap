/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:03:58 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/24 16:38:53 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ifupdown(int	tab, t_list *stack)
{
	
	int	mid = ft_lstsize(stack) / 2 ;
	int count;
	count = 1;
	while (stack)
	{
		if (stack->content == tab)
			break;
		count++;
		stack = stack->next;
	}
	if (count >= mid)
		return (1);
	return (0);
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
		
	// 	while (stack)
	// 	{
	// 		printf("\n|stack a|\t%d", stack->content);
	// 		stack = stack->next;
	// 	}
	// // 	printf("\n\n\n");
		
	// 	while (stackb)
	// 	{
	// 		printf("\n|stack b|\t%d", stackb->content);
	// 		stackb = stackb->next;
	// while (index < ft_lstsize(stack))
	// 	{
	// 		printf("%d sorted|%d|\n", index, tab[index]);
	// 		index++;
	// 	}
	}
}
