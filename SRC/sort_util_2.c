/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:29:00 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/23 05:48:19 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting(t_list ** stack_a, t_list ** stack_b, int *sort_tab)
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