/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/05 23:59:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	soph_child_loop_release(sem_t *sem, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		sem_post(sem);
		i++;
	}
	if (n < N_RESOURCE)
		return (false);
	return (true);
}

static bool	soph_child_loop_hold(t_var *var, sem_t *sem, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		sem_wait(sem);
		soph_print_log(soph_gettime(), var->id, MSG_HOLD, var);
		i++;
		if (i == var->param->n_proc && i < N_RESOURCE)
			return (soph_child_loop_release(sem, i));
	}
	return (true);
}

static void	soph_child_loop(t_param *param, t_var *var, sem_t **sems)
{
	long	ts;

	while (param->max_turn == TURN_INF || var->turn < param->max_turn)
	{
		if (!soph_child_loop_hold(var, sems[IDX_RSRC], N_RESOURCE))
			break ;
		ts = soph_gettime();
		var->ts_target = ts + param->timeout;
		soph_print_log(ts, var->id, MSG_EXEC, var);
		usleep(param->time_exec - TIME_TACK);
		while (soph_gettime() < ts + param->time_exec)
			usleep(TIME_TICK);
		soph_child_loop_release(sems[IDX_RSRC], N_RESOURCE);
		ts = soph_gettime() + param->time_sleep;
		soph_print_log(ts - param->time_sleep, var->id, MSG_SLEEP, var);
		var->turn++;
		usleep(param->time_sleep - TIME_TACK);
		while (soph_gettime() < ts)
			usleep(TIME_TICK);
		soph_print_log(soph_gettime(), var->id, MSG_QUEUE, var);
		if (param->time_queue > TIME_TACK)
			usleep(param->time_queue - TIME_TACK);
		while (soph_gettime() < ts + param->time_queue)
			usleep(TIME_TICK);
	}
}

int	soph_child(t_var *var, pid_t *pids)
{
	t_thd	thd;
	long	ts_tmp;
	int		time_pre;

	free(pids);
	time_pre = soph_calc_preempt(var);
	ts_tmp = var->ts_target;
	errno = soph_child_thread_create(&thd, var);
	if (errno)
	{
		free(var->sems);
		return (errno);
	}
	while (var->ts_target == ts_tmp)
		usleep(TIME_TICK);
	soph_print_log(soph_gettime(), var->id, MSG_QUEUE, var);
	usleep(time_pre);
	soph_child_loop(var->param, var, var->sems);
	soph_child_thread_join(&thd);
	free(var->sems);
	return (ERR_NOERR);
}
