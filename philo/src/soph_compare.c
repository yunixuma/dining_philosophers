/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/18 05:08:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	soph_compare_ts_static(t_var *var, int ts_tgt)
{
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	if (var[0].ts_target == ts_tgt)
	{
		pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
		return (true);
	}
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
	return (false);
}

bool	soph_compare_turn_static(t_var *var, int turn_tgt)
{
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	if (var[0].param->max_turn == turn_tgt)
	{
		pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
		return (true);
	}
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
	return (false);
}

bool	soph_compare_turn_dynamic(t_var *var, int id)
{
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	if (var[0].param->max_turn > var[id].turn)
	{
		pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
		return (true);
	}
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
	return (false);
}
