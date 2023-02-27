/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_thread_main_fast.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/10 16:57:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	soph_thread_main_loop_release(t_rsrc *rsrc, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		rsrc[i].state = STATE_FREE;
		pthread_mutex_unlock(rsrc[i].mtx);
		i++;
	}
	if (n < N_RESOURCE)
		return (false);
	return (true);
}

static bool	\
	soph_thread_main_loop_hold(t_rsrc *rsrc, int n, int i_thd, t_var *var)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_lock(rsrc[i].mtx);
		rsrc[i].state = i_thd;
		soph_print_log(soph_gettime(), i_thd, MSG_HOLD, var);
		i++;
		if (i == var->param->n_thd && i < N_RESOURCE)
			return (soph_thread_main_loop_release(rsrc, i));
	}
	return (true);
}

static void	\
	soph_thread_main_loop(t_var *var, t_param *param, int i_thd, t_rsrc *rsrc)
{
	long	ts;

	while (param->max_turn != TURN_TERM)
	{
		if (!soph_thread_main_loop_hold(rsrc, N_RESOURCE, i_thd, var))
			break ;
		ts = soph_gettime();
		var->ts_target = ts + param->timeout;
		soph_print_log(ts, i_thd, MSG_EXEC, var);
		usleep(param->time_exec - TIME_TACK);
		while (soph_gettime() < ts + param->time_exec)
			usleep(TIME_TICK);
		soph_thread_main_loop_release(rsrc, N_RESOURCE);
		ts = soph_gettime() + param->time_sleep;
		soph_print_log(ts - param->time_sleep, i_thd, MSG_SLEEP, var);
		var->turn++;
		usleep(param->time_sleep - TIME_TACK);
		while (soph_gettime() < ts)
			usleep(TIME_TICK);
		soph_print_log(soph_gettime(), i_thd, MSG_QUEUE, var);
		if (param->time_queue > TIME_TACK)
			usleep(param->time_queue - TIME_TACK);
		while (soph_gettime() < ts + param->time_queue)
			usleep(TIME_TICK);
	}
}

void	*soph_thread_main(void *p)
{
	t_var	*var;
	int		time_pre;

	var = (t_var *)p;
	time_pre = soph_calc_preempt(var);
	while (soph_gettime() < var->ts_target)
		usleep(TIME_TICK);
	soph_print_log(soph_gettime(), var->id, MSG_QUEUE, var);
	usleep(time_pre);
	soph_thread_main_loop(var, var->param, var->id, var->rsrc);
	return (NULL);
}
