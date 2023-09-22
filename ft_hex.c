/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:02:35 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/20 15:00:18 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_make_hex(unsigned long n, char c)
{
	if (n >= 16)
	{
		ft_make_hex(n / 16, c);
		ft_make_hex(n % 16, c);
	}
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd((n + 48), 1);
		else if (c == 'x')
			ft_putchar_fd((n + 87), 1);
		else
			ft_putchar_fd((n + 55), 1);
	}
}

static int	ft_hex_len(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16 != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_hex(unsigned int n, char c)
{
	ft_make_hex(n, c);
	return (ft_hex_len(n));
}

int	ft_ptr(unsigned long ptr)
{
	write(1, "0x", 2);
	ft_make_hex(ptr, 'x');
	return (ft_hex_len(ptr) + 2);
}

// int	main(void)
// {
// 	unsigned long a = 495;
// 	void *ptr = &a;
// 	// int i = 0;
// 	// ft_make_hex(a, 'X');
// 	// printf("\t%d\n", ft_hex_len(a));
// 	printf("%p\n\n", ptr);
// 	ft_ptr(ptr);
// 	// printf("\t%d", (printf("\n\n%X", a) - 2));
// 	// printf("%p", ptr);
// 	// printf("%p", &ptr);
// }