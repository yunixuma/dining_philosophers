/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_setvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/16 14:15:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_var	soph_setvar(t_param *param, sem_t **sems)
{
	t_var	var;

	var.id = 0;
	var.param = param;
	var.sems = sems;
	var.ts_target = soph_gettime();
	var.turn = 0;
	return (var);
}

void	soph_setvar_turn_incr(t_var *var)
{
	sem_wait(var->sems[IDX_LIMIT]);
	var->turn++;
	sem_post(var->sems[IDX_LIMIT]);
}

void	soph_setvar_ts_upd(t_var *var, long ts)
{
	sem_wait(var->sems[IDX_MONI]);
	var->ts_target = ts + var->param->timeout;
	sem_post(var->sems[IDX_MONI]);
}
