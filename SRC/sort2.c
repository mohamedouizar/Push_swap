/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:28:18 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/26 19:29:41 by mouizar          ###   ########.fr       */
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
