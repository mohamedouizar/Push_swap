/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:52:29 by mouizar           #+#    #+#             */
/*   Updated: 2021/12/15 14:58:09 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*(str + i))
		i++;
	write(1, str, i);
	return (i);
}

static int	ft_lenn(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	unsigned int	n;
	int				len;

	len = ft_lenn(nb);
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	n = nb;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putnbru(unsigned int nb)
{
	int	len;

	len = ft_lenn(nb);
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (len);
}
