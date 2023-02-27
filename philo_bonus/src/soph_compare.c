/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/16 11:09:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	soph_compare_ts_static(t_var *var, int ts_tgt)
{
	sem_wait(var->sems[IDX_MONI]);
	if (var[0].ts_target == ts_tgt)
	{
		sem_post(var->sems[IDX_MONI]);
		return (true);
	}
	sem_post(var->sems[IDX_MONI]);
	return (false);
}

bool	soph_compare_turn_static(t_var *var, int turn_tgt)
{
	sem_wait(var->sems[IDX_LIMIT]);
	if (var[0].param->max_turn == turn_tgt)
	{
		sem_post(var->sems[IDX_LIMIT]);
		return (true);
	}
	sem_post(var->sems[IDX_LIMIT]);
	return (false);
}

bool	soph_compare_turn_dynamic(t_var *var)
{
	sem_wait(var->sems[IDX_LIMIT]);
	if (var[0].param->max_turn > var[0].turn)
	{
		sem_post(var->sems[IDX_LIMIT]);
		return (true);
	}
	sem_post(var->sems[IDX_LIMIT]);
	return (false);
}
