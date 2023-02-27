/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_child_moni.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/16 11:19:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	soph_child_moni_chkturn(t_var *var)
{
	if (soph_compare_turn_static(var, TURN_INF))
		return (true);
	else if (soph_compare_turn_dynamic(var))
		return (true);
	return (false);
}

static int	soph_child_moni_kill(int i_proc, long ts, t_var *var)
{
	sem_wait(var->sems[IDX_IO]);
	if (ts < var->ts_target)
	{
		sem_post(var->sems[IDX_IO]);
		return (false);
	}
	var->param->max_turn = TURN_TERM;
	sem_post(var->sems[IDX_LIMIT]);
	printf(MSG_LOG, ts / 1000, LEN_ID, i_proc + 1, MSG_TIMEOUT);
	return (true);
}

void	*soph_child_moni(void *p)
{
	t_var	*var;
	long	ts;

	var = (t_var *)p;
	sem_wait(var->sems[IDX_MONI]);
	while (soph_gettime() < var->ts_target)
		usleep(TIME_TICK);
	var->ts_target = soph_gettime() + var->param->timeout;
	sem_post(var->sems[IDX_MONI]);
	while (soph_child_moni_chkturn(var))
	{
		usleep(TIME_TACK >> 1);
		ts = soph_gettime();
		sem_wait(var->sems[IDX_MONI]);
		if (ts >= var->ts_target)
		{
			if (soph_child_moni_kill(var->id, ts, var))
				exit(ERR_TIMEOUT);
		}
		sem_post(var->sems[IDX_MONI]);
	}
	return (NULL);
}
