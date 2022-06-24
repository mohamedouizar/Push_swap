/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:12:03 by mouizar           #+#    #+#             */
/*   Updated: 2021/12/16 21:33:30 by mouizar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_test_format(char *form, va_list comp, int i, int count)
{
	if (*(form + i + 1) == 'c')
		count += ft_putchar(va_arg(comp, int));
	else if ((*(form + i + 1) == 'd') || (*(form + i + 1) == 'i'))
		count += ft_putnbr(va_arg(comp, int));
	else if ((*(form + i + 1)) == 'u')
		count += ft_putnbru(va_arg(comp, unsigned int));
	else if (*(form + i + 1) == 's')
		count += ft_putstr(va_arg(comp, char *));
	else if (*(form + i + 1) == 'x')
		ft_converthex(va_arg(comp, unsigned int), &count, 1);
	else if (*(form + i + 1) == 'X')
		ft_converthex(va_arg(comp, unsigned int), &count, 0);
	else if (*(form + i + 1) == '%')
		count += ft_putchar('%');
	else if (*(form + i + 1) == 'p')
	{
		count += ft_putstr("0x");
		ft_converthex2(va_arg(comp, unsigned long), &count, 1);
	}
	return (count);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		count;
	va_list	comp;

	va_start (comp, form);
	count = 0;
	i = 0;
	while (form[i])
	{
		if (*(form + i) == '%')
		{
			count = ft_test_format((char *)form, comp, i, count);
			i++;
		}
		else
			count += ft_putchar(form[i]);
		i++;
	}
	va_end(comp);
	return (count);
}
