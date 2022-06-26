/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:29:52 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/26 19:30:25 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_assign(t_var *var, t_list *stack_a)
{
	var->s = ft_lstsize((stack_a)) - 1;
	var->offset = offset_count(ft_lstsize((stack_a)));
	var->mid = ft_lstsize((stack_a)) / 2;
	var->start = var->mid - var->offset;
	var->end = var->mid + var->offset;
}

void	stack_a_to_b(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_var	var;

	ft_assign(&var, (*stack_a));
	while (ft_lstsize((*stack_a)))
	{
		while (ft_lstsize(*stack_b) <= var.end - var.start)
		{
			if ((*stack_a)->content >= tab[var.start]
				&& (*stack_a)->content <= tab[var.end])
			{
				ft_push(stack_b, stack_a, 'b');
				if ((*stack_b)->content < tab[var.mid])
					ft_rot(stack_b, 'b');
			}		
			else
				ft_rot(stack_a, 'a');
		}
		var.start -= var.offset;
		if (var.start < 0)
			var.start = 0;
		var.end += var.offset;
		if (var.end > var.s)
			var.end = var.s;
	}
}

void	ft_apply_bit_sort(t_list **stack_a,
	int *tab, t_list **stack_b, t_var *var)
{
	if ((*stack_b)->content == tab[var->s])
	{
		ft_push(stack_a, stack_b, 'a');
		var->s -= 1;
	}
	else if (var->cmp == 0 || (*stack_b)->content > lastin_stack((*stack_a)))
	{
		ft_push(stack_a, stack_b, 'a');
		ft_rot(stack_a, 'a');
		var->cmp++;
	}
	else
	{
		if (check_ifupdown(tab[var->s], *stack_b) == 0)
			ft_rot(stack_b, 'b');
		else
			ft_rrot(stack_b, 'b');
	}
}

void	big_sort(t_list **stack_a, int *tab, t_list **stack_b)
{
	t_var	var;

	var.s = ft_lstsize((*stack_a)) - 1;
	var.cmp = 0;
	stack_a_to_b(stack_a, stack_b, tab);
	while ((*stack_b))
	{
		if (check_if_exist(tab[var.s], (*stack_b)))
			ft_apply_bit_sort(stack_a, tab, stack_b, &var);
		else if (!(check_if_exist(tab[var.s], (*stack_b))) && var.cmp > 0)
		{
			ft_rrot(stack_a, 'a');
			var.cmp--;
			var.s--;
		}
	}
	while (var.cmp > 0)
	{
		ft_rrot(stack_a, 'a');
		var.cmp--;
	}
}
