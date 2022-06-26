/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:56:08 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/26 19:36:55 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
		new->next = *lst;
		*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (*lst)
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = NULL;
	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element -> content = content;
	element -> next = NULL;
	return (element);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
