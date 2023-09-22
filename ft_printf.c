/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:46:12 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/01/19 16:04:18 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select(va_list list, const char *s, size_t i)
{
	if (s[i + 1] == 0)
		return (0);
	else if (s[i + 1] == 'c')
		return (ft_char(va_arg(list, int)));
	else if (s[i + 1] == 's')
		return (ft_str(va_arg(list, char *)));
	else if (s[i + 1] == 'p')
		return (ft_ptr(va_arg(list, unsigned long)));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_int(va_arg(list, int)));
	else if (s[i + 1] == 'u')
		return (ft_uns_int(va_arg(list, unsigned int)));
	else if (s[i + 1] == 'x' || s[i + 1] == 'X')
		return (ft_hex(va_arg(list, unsigned long), s[i + 1]));
	else if (s[i + 1] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		while (s[i] == '%')
		{
			count += ft_select(list, s, i);
			if (s[i + 1])
				i += 2;
			else
				i++;
		}
		if (s[i])
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(list);
	return (count);
}
