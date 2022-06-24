/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:08:06 by mouizar           #+#    #+#             */
/*   Updated: 2021/12/17 00:21:01 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printf(const char *form, ...);
int		ft_putstr(char *str);
int		ft_test_format(char *form, va_list comp, int i, int count);
int		ft_putnbr(int nb);
void	ft_converthex(unsigned int nb, int *count, int a);
void	ft_converthex2(unsigned long nb, int *count, int a);
int		ft_toupper(int c);
int		ft_putnbru(unsigned int nb);
#endif