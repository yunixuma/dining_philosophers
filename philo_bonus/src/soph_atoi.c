/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:57:55 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/19 00:58:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	soph_atoi(const char *str)
{
	int		nb;
	size_t	i;

	if (str == NULL)
		return (-1);
	if (*str == '+')
		str++;
	nb = 0;
	i = 0;
	while (*(str + i) != '\0' && i < 10)
	{
		if (!ft_isdigit(*(str + i)))
			return (-1);
		nb = nb * 10 + *(str + i) - '0';
		i++;
	}
	if (i == 10 && ft_strncmp(str, STR_INTMAX, 10) > 0)
		return (INT_MIN);
	return (nb);
}
