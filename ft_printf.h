/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:32:05 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 12:59:13 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_char(char c);
int		ft_int(int n);
int		ft_str(char *s);
int		ft_printf(const char *s, ...);
int		ft_select(va_list list, const char *s, size_t i);
void	ft_free(char *str);
char	*ft_itoa_unsigned(unsigned long n);
int		ft_uns_int(unsigned int n);
int		ft_hex(unsigned int n, char c);
int		ft_ptr(unsigned long ptr);

#endif