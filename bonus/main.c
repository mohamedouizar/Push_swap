/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:43:19 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 22:23:35 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	stack_is_sorted(t_list *stack, t_list *stack_b)
{
	int		size_b;

	size_b = ft_lstsize(stack_b);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			break ;
	}
	if ((!stack->next) && size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

void	compare_oper(t_list **stack_a, t_list **stack_b, char *oper)
{
	if (ft_strcmp(oper, "sa\n") == 0)
		ft_swap(*stack_a, 0);
	else if (ft_strcmp(oper, "sb\n") == 0)
		ft_swap(*stack_a, 0);
	else if (ft_strcmp(oper, "pa\n") == 0)
		ft_push(stack_a, stack_b, 0);
	else if (ft_strcmp(oper, "pb\n") == 0)
		ft_push(stack_b, stack_a, 0);
	else if (ft_strcmp(oper, "ra\n") == 0)
		ft_rot(stack_a, 0);
	else if (ft_strcmp(oper, "rb\n") == 0)
		ft_rot(stack_b, 0);
	else if (ft_strcmp(oper, "rra\n") == 0)
		ft_rrot(stack_a, 0);
	else if (ft_strcmp(oper, "rrb\n") == 0)
		ft_rrot(stack_b, 0);
	else if (ft_strcmp(oper, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(oper, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(oper, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else if (oper)
		exit(write(2, "Error\n", 6));
	free (oper);
}

void	call_operation(t_list *stack_a, t_list *stack_b)
{
	char	*oper;

	oper = "loading";
	while (oper)
	{
		oper = get_next_line(0);
		if (!oper)
			break ;
		compare_oper(&stack_a, &stack_b, oper);
	}
	stack_is_sorted(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_check_av(ac, av);
		add_av_tostack(av, ac, &stack_a);
		call_operation(stack_a, stack_b);
	}
	return (0);
}
