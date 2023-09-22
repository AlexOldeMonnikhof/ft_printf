/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:46:22 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 12:53:47 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_counter(unsigned long n)
{
	size_t	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned long n)
{
	size_t	count;
	char	*str;

	count = ft_counter(n);
	str = (char *)malloc(count * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[count] = 0;
	if (n == 0)
		str[0] = '0';
	while (count > 0)
	{
		str[count - 1] = n % 10 + '0';
		n /= 10;
		count--;
	}
	return (str);
}
