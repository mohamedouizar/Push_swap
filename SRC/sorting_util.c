/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:08:05 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/26 00:03:36 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	small_content_i(t_list	*stack)
{
	int	i;
	int	small_i;
	int	min;

	i = 1;
	small_i = i;
	min = stack->content;
	while (stack->next)
	{
		if (min > stack->next->content)
		{
			min = stack->next->content;
			small_i = i + 1;
		}
		stack = stack->next;
		i++;
	}
	return (small_i);
}

int	*convert_ls_to_array(t_list *stack)
{
	int	size_ls;
	int	i;
	int	*tab;

	i = 0;
	size_ls = ft_lstsize(stack);
	tab = (int *)malloc(size_ls * sizeof(int));
	if (!tab)
		exit(0);
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	ft_buble_sort(tab, size_ls);
	return (tab);
}

int	offset_count(int size)
{
	if (size < 150)
		return (size / 8);
	else
		return (size / 22);
}

int	check_if_exist(int to_find, t_list	*stack)
{
	while (stack)
	{
		if(stack->content == to_find)
			return (1);
		stack = stack->next;
	}
	return (0);
}