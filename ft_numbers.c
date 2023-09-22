/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:19 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 13:34:07 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_int(int n)
{
	char	*str;
	int		length;

	str = ft_itoa(n);
	if (!str)
		return (0);
	length = ft_strlen(str);
	write(1, str, length);
	free(str);
	return (length);
}

int	ft_uns_int(unsigned int n)
{
	char	*str;
	int		length;

	str = ft_itoa_unsigned(n);
	if (!str)
		return (0);
	length = ft_strlen(str);
	write(1, str, length);
	free(str);
	return (length);
}
