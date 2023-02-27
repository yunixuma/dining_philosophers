/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/07 22:54:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	soph_calc_phase_unit(t_param *param)
{
	int	div;

	if (param->n_proc < N_RESOURCE + 1)
		return (TIME_TACK);
	div = (param->n_proc - 1) / N_RESOURCE;
	return (param->time_exec / div);
}

int	soph_calc_queue(t_param *param)
{
	int		time_queue;
	int		time_unit;

	time_unit = soph_calc_phase_unit(param);
	time_queue = soph_calc_phase_unit(param) * (param->n_proc % N_RESOURCE);
	time_queue += param->time_exec * (N_RESOURCE - 1) - param->time_sleep;
	if (time_unit * 2 < TIME_TACK * 3)
		time_queue -= (time_unit >> 1);
	else
		time_queue -= TIME_TACK;
	if (time_queue < 0)
		return (0);
	return (time_queue);
}

static int	soph_calc_preempt_sub(t_var *var)
{
	int	time_pre;
	int	time_unit;

	time_unit = soph_calc_phase_unit(var->param);
	time_pre = var->id * time_unit;
	if (time_unit * 2 < TIME_TACK * 3)
		time_pre -= (time_unit >> 1);
	else
		time_pre -= TIME_TACK;
	if (time_pre < 0)
		return (0);
	return (time_pre);
}

int	soph_calc_preempt(t_var *var)
{
	int	time_pre;

	if (var->id == 0)
		return (TIME_ZERO);
	else if (var->param->n_proc % N_RESOURCE == 0)
	{
		time_pre = var->id % N_RESOURCE;
		time_pre *= var->param->time_exec;
		if (time_pre > TIME_TACK)
			time_pre -= TIME_TACK;
		return (time_pre);
	}
	else if (var->param->n_proc < N_RESOURCE)
		return (var->id * TIME_TACK);
	return (soph_calc_preempt_sub(var));
}
