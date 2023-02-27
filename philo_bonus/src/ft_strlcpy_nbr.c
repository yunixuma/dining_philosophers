/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:55:08 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/30 11:56:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	\
	*ft_strlcpy_nbr_setstr(char *str, unsigned long long n_abs, size_t dig)
{
	unsigned long long	n_tmp;

	*(str + dig) = '\0';
	if (n_abs == 0)
		return (ft_memset(str, '0', 1));
	while (n_abs > 0)
	{
		n_tmp = n_abs / 10;
		dig--;
		*(str + dig) = n_abs - n_tmp * 10 + '0';
		n_abs = n_tmp;
	}
	if (dig > 0)
		*str = '-';
	return (str);
}

static size_t	ft_strlcpy_nbr_getdig(unsigned long long n_abs)
{
	size_t		dig;

	dig = 1;
	while (n_abs >= 10)
	{
		dig++;
		n_abs = n_abs / 10;
	}
	return (dig);
}

size_t	ft_strlcpy_nbr(char *str, long long n, size_t len)
{
	unsigned long long	n_abs;
	size_t				dig;
	size_t				pad;

	if (n < 0)
		n_abs = -(unsigned long long)n;
	else
		n_abs = n;
	dig = (n < 0) + ft_strlcpy_nbr_getdig(n_abs);
	if (len > dig)
		pad = len - dig;
	else
		pad = 0;
	ft_memset(str, CHR_PAD, pad);
	ft_strlcpy_nbr_setstr(str + pad, n_abs, dig);
	return (dig);
}
