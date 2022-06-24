/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:59:12 by mouizar           #+#    #+#             */
/*   Updated: 2021/12/15 15:07:58 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converthex(unsigned int nb, int *count, int a)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_converthex(nb / 16, count, a);
	if (a == 1)
		*count += ft_putchar(base[nb % 16]);
	if (a == 0)
		*count += ft_putchar(ft_toupper(base[nb % 16]));
}

void	ft_converthex2(unsigned long nb, int *count, int a)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_converthex2(nb / 16, count, a);
	if (a == 1)
		*count += ft_putchar(base[nb % 16]);
	if (a == 0)
		*count += ft_putchar(ft_toupper(base[nb % 16]));
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
