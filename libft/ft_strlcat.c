/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:13:27 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:25 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (i < src_len && i + dst_len + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	if (dstsize < dst_len)
		return (dstsize + src_len);
	else
		return (dst_len + src_len);
}

// int	main(void)
// {
// 	dest[14] = 'a';
// 	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
// }
