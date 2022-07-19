/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamedouizar <mohamedouizar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:29:00 by mouizar           #+#    #+#             */
/*   Updated: 2022/07/18 23:09:45 by mohamedouiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting(t_list **stack_a, t_list **stack_b, int *sort_tab)
{
	int	size;

	size = ft_lstsize((*stack_a));
	if (size == 2)
		ft_sort_2(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size <= 15)
		ft_sort_15(stack_a, stack_b);
	else
		big_sort(stack_a, sort_tab, stack_b);
}
