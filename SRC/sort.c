/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:02:45 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/23 07:33:07 by mouizar          ###   ########.fr       */
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
	else if ((*stack)->next->content > (*stack)->content && (*stack)->next->content
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

void	big_sort(t_list **stack_a, int *tab,t_list **stack_b)
{
	int	offset;
	int	mid;
	int	start;
	int	end;
	int	s;
	int	cmp;

	s = ft_lstsize((*stack_a)) - 1;
	offset = offset_count(ft_lstsize((*stack_a)));
	mid = ft_lstsize((*stack_a)) / 2;
	start = mid - offset;
	end = mid + offset;
	cmp = 0;
	

	// printf("ofsett is ; {%d}\n",offset);
	// printf("mid  is ; {%d}\n",mid);
	// printf("********************size   is ; {%d}\n",s);
	// printf("****last in stack a    is ; {%d}\n", lastin_stack((*stack_a)));
	
	while(ft_lstsize(*stack_b) <= end - start)
	{
		//printf("...%d...%d\n", start, end);
		if ((*stack_a)->content >= tab[start] && (*stack_a)->content <= tab[end])
		{
			ft_push(stack_b, stack_a, 'b');
			if ((*stack_b)->content > tab[mid])
				ft_rot(stack_b, 'b');
		}
		else
			ft_rot(stack_a, 'a');
		start -= offset;
		if (start < 0)
			start = 0;
		end += offset;
		if (end > ft_lstsize((*stack_a)) - 1)
			end = s;
	}
	// printf("********************size   is ; {%d}\n",s);
	// printf("bigger sorted tab is %d\n", tab[s]);
	while ((*stack_b))
	{
	
		if (check_if_exist(tab[s], (*stack_b)))
		 {
			if ((*stack_b)->content == tab[s])
			{
		 		ft_push(stack_a, stack_b,'a');
				s--;
			}
			else if ((cmp == 0 || (*stack_b)->content > lastin_stack((*stack_a))))
			{
				ft_push(stack_a, stack_b,'a');
		 			ft_rot(stack_a, 'a');
		 			cmp++;
			}
			else
	 			ft_rot(stack_b, 'b');	
		 }
		else if (!(check_if_exist(tab[s], (*stack_b))))
		{
		 	ft_rrot(stack_a, 'a');
			cmp--;
			s--;
		}
	}
	while (cmp)
	{
		ft_rrot(stack_a, 'a');
		cmp--;
	}
	
}

