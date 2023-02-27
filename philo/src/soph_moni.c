/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_moni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/18 05:18:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	soph_moni_chkturn(t_var *var)
{
	ssize_t	i;

	if (soph_compare_turn_static(var, TURN_INF))
		return (true);
	else if (soph_compare_turn_static(var, TURN_TERM))
		return (false);
	i = 0;
	while (i < var[0].param->n_thd)
	{
		if (soph_compare_turn_dynamic(var, i++))
			return (true);
	}
	return (false);
}

static int	soph_moni_kill(int i_thd, long ts, t_var *var)
{
	pthread_mutex_lock(&var->mtx[IDX_IO]);
	if (ts < var[i_thd].ts_target)
	{
		pthread_mutex_unlock(&var->mtx[IDX_IO]);
		return (false);
	}
	pthread_mutex_unlock(&var->mtx[IDX_MONI]);
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	var[i_thd].param->max_turn = TURN_TERM;
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
	printf(MSG_LOG, ts / 1000, LEN_ID, i_thd + 1, MSG_TIMEOUT);
	pthread_mutex_unlock(&var->mtx[IDX_IO]);
	return (true);
}

void	soph_moni(t_var *var)
{
	long	ts;
	ssize_t	i;

	usleep(var->param->timeout - (TIME_TACK >> 1));
	while (soph_moni_chkturn(var))
	{
		usleep(TIME_TACK >> 1);
		ts = soph_gettime();
		i = 0;
		while (i < var[0].param->n_thd)
		{
			pthread_mutex_lock(&var->mtx[IDX_MONI]);
			if (ts >= var[i].ts_target)
			{
				if (soph_moni_kill(i, ts, var))
					return ;
			}
			pthread_mutex_unlock(&var->mtx[IDX_MONI]);
			i++;
		}
	}
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	var[0].param->max_turn = TURN_TERM;
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
}
