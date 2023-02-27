/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/07 14:34:19 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	soph_calc_phase_unit(t_param *param)
{
	long	div;

	if (param->n_thd < N_RESOURCE + 1)
		return (TIME_TACK);
	div = (param->n_thd - 1) / N_RESOURCE;
	return (param->time_exec / div);
}

int	soph_calc_queue(t_param *param)
{
	int	time;

	time = soph_calc_phase_unit(param) * (param->n_thd % N_RESOURCE);
	time += param->time_exec * (N_RESOURCE - 1) - param->time_sleep;
	time -= TIME_TACK;
	if (time < 0)
		return (0);
	return (time);
}

static long	soph_calc_round(t_var *var, int offset)
{
	int		round;

	round = 0;
	while (round < N_RESOURCE)
	{
		if ((var->id + round * (var->param->n_thd + offset)) % N_RESOURCE == 0)
			return (round);
		round++;
	}
	if (offset + 1 < N_RESOURCE && offset + 2 < MAX_RECURSE)
		return (soph_calc_round(var, offset + 1));
	return (0);
}

static long	soph_calc_preempt_sub(t_var *var)
{
	long	time_pre;
	long	time_unit;
	int		round;

	time_unit = soph_calc_phase_unit(var->param);
	time_pre = var->id / N_RESOURCE;
	time_pre *= time_unit;
	round = soph_calc_round(var, 0);
	time_pre += round * var->param->time_exec;
	if (time_unit * 2 < TIME_TACK * 3)
		time_pre -= (time_unit >> 1);
	else
		time_pre -= TIME_TACK;
	if (time_pre < 0)
		return (0);
	return (time_pre);
}

long	soph_calc_preempt(t_var *var)
{
	long	time_pre;

	if (var->id == 0)
		return (TIME_ZERO);
	else if (var->param->n_thd % N_RESOURCE == 0)
	{
		time_pre = (var->id % N_RESOURCE) * var->param->time_exec;
		if (time_pre > TIME_TACK)
			time_pre -= TIME_TACK;
		return (time_pre);
	}
	else if (var->param->n_thd < N_RESOURCE)
		return (var->id * TIME_TACK);
	return (soph_calc_preempt_sub(var));
}
