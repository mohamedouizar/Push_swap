/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:02:45 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 22:29:12mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_2(t_list	**stack)
{
	if ((*stack)->content > (*stack)->next->content)
		ft_swap((*stack), 'a');
}

void	ft_sort_3(t_list	**stack)
{
	if ((*stack)->content > (*stack)->next->content && (*stack)->content
		> (*stack)->next->next->content)
		ft_rot((stack), 'a');
	else if ((*stack)->next->content
		> (*stack)->content && (*stack)->next->content
		> (*stack)->next->next->content)
		ft_rrot((stack), 'a');
	ft_sort_2(stack);
}

void	ft_sort_15(t_list	**stacka, t_list	**stackb)
{
	int	size;
	int	i;

	size = ft_lstsize(*(stacka));
	while (size > 3)
	{
		i = small_content_i((*stacka));
		if (i == 1)
		{
			ft_push(stackb, stacka, 'b');
			size--;
		}
		else if (i > size / 2)
			ft_rrot(stacka, 'a');
		else
			ft_rot(stacka, 'a');
	}
	ft_sort_3(stacka);
	while ((*stackb))
	{
		ft_push(stacka, stackb, 'a');
	}
}

void	ft_buble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

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

void	ft_apply_bit_sort(t_list **stack_a, int *tab, t_list **stack_b, t_var *var)
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
