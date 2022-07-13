/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamedouizar <mohamedouizar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:44:02 by mouizar           #+#    #+#             */
/*   Updated: 2022/07/08 16:49:58:33hamedouiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list *stack, char c)
{
	int	tmp;

	if (ft_lstsize(stack) < 2)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_push(t_list **from, t_list	**to, char c)
{
	int		tmp;
	t_list	*temp;
	int		cmp;

	cmp = ft_lstsize(*to);
	if (cmp < 1)
		return ;
	tmp = (*to)->content;
	temp = (*to)->next;
	free(*to);
	ft_lstadd_front(from, ft_lstnew(tmp));
	*to = temp;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
	{
		ft_putstr_fd("pb\n", 1);
	}
}

void	ft_rot(t_list **stack, char c)
{
	int		tmp1;
	t_list	*temp;
	int		cmp;

	cmp = ft_lstsize((*stack));
	if (cmp < 2)
		return ;
	tmp1 = (*stack)->content;
	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
	ft_lstadd_back(stack, ft_lstnew(tmp1));
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_rrot(t_list **stack, char c)
{
	t_list	*head;
	int		cmp;

	cmp = ft_lstsize((*stack));
	if (cmp < 2)
		return ;
	head = (*stack);
	while (head->next->next)
		head = head->next;
	ft_lstadd_front(stack, head->next);
	head->next = 0;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}