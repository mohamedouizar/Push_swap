/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:42:24 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/25 20:44:21 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap((*stack_a), 0);
	ft_swap((*stack_b), 0);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rot(&(*stack_a), 0);
	ft_rot(&(*stack_b), 0);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrot(&(*stack_a), 0);
	ft_rrot(&(*stack_b), 0);
}
