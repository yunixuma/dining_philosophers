/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/02 13:42:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	len;
	ssize_t	ret;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	ret = 0;
	while (len > INT_MAX)
	{
		ret += write(fd, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	ret += write(fd, s, len);
	return (ret);
}
