/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:54:08 by mouizar           #+#    #+#             */
/*   Updated: 2022/06/23 00:30:37 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_s_digit(char	*str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_av_digit(int arc, char **arv);
int		ft_av_dup(int arc, char **arv);
int		ft_maxint(int ac, char **av);
int		ft_empty_av(int ac, char **av);
int		ft_check_av(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	check_sorted(t_list *stack);
void	ft_swap(t_list *stack, char c);
void	ft_push(t_list **stack_a, t_list	**stack_b, char c);
void	ft_rot(t_list **stack, char c);
void	ft_rrot(t_list **stack, char c);
int		lastin_stack(t_list *stack);
void	ft_sort_2(t_list	**stack);
void	ft_sort_3(t_list	**stack);
void	ft_sort_15(t_list	**stacka, t_list	**stackb);
void	ft_buble_sort(int *tab, int len);
void	big_sort(t_list **stack_a, int *tab,t_list **stack_b);
int		small_content_i(t_list	*stack);
int		*convert_ls_to_array(t_list *stack);
int		offset_count(int size);
int		check_if_exist(int to_find, t_list	*stack);
void	add_av_tostack(char	**av,int ac, t_list **stack);
void	sorting(t_list ** stack_a, t_list ** stack_b, int *sort_tab);

#endif