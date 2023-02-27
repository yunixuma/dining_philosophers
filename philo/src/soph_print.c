/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/18 04:41:15 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	soph_print_log(long ts, int i_thd, const char *msg, t_var *var)
{
	char	str[LEN_LOG];

	if (soph_compare_turn_static(var, TURN_TERM))
		return ;
	ft_strlcpy_nbr(str, ts / 1000, LEN_TS);
	ft_strlcpy_nbr(str + ft_strlen(str), i_thd + 1, LEN_ID);
	ft_strlcpy(str + ft_strlen(str), msg, LEN_MSG);
	pthread_mutex_lock(&var->mtx[IDX_IO]);
	ft_putstr_fd(str, STDOUT_FILENO);
	pthread_mutex_unlock(&var->mtx[IDX_IO]);
}

static void	soph_print_usage(void)
{
	ft_putstr_fd(MSG_USAGE, STDERR_FILENO);
	ft_putstr_fd(MSG_ARG_A, STDERR_FILENO);
	ft_putstr_fd(MSG_ARG_B, STDERR_FILENO);
	ft_putstr_fd(MSG_ARG_C, STDERR_FILENO);
	ft_putstr_fd(MSG_ARG_D, STDERR_FILENO);
	ft_putstr_fd(MSG_ARG_E, STDERR_FILENO);
}

int	soph_print_err(int errnum)
{
	ft_putstr_fd(MSG_ERR, STDERR_FILENO);
	if (errnum == ERR_ARG)
		ft_putstr_fd(MSG_ARG, STDERR_FILENO);
	else if (errnum == ERR_NUM)
		ft_putstr_fd(MSG_NUM, STDERR_FILENO);
	else if (errnum == ERR_TIME)
		ft_putstr_fd(MSG_TIME, STDERR_FILENO);
	else if (errnum == ERR_ALLOC)
		ft_putstr_fd(MSG_ALLOC, STDERR_FILENO);
	else if (errnum == ERR_RSRC)
		ft_putstr_fd(MSG_RSRC, STDERR_FILENO);
	if (errnum == ERR_ARG || errnum == ERR_NUM || errnum == ERR_TIME)
		soph_print_usage();
	return (errnum);
}
