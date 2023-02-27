/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_thread_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/19 08:05:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	soph_thread_main_loop_release(t_var *var, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_lock(var->rsrc[i].mtx);
		if (*var->rsrc[i].state == var->id)
			*var->rsrc[i].state = STATE_FREE;
		pthread_mutex_unlock(var->rsrc[i].mtx);
		i++;
	}
	if (n < N_RESOURCE)
		return (false);
	return (true);
}

static bool	soph_thread_main_loop_hold(t_var *var, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		soph_print_log(soph_gettime(), var->id, MSG_HOLD, var);
		i++;
	}
	return (true);
}

static bool	soph_thread_main_loop_book(t_var *var, int n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_lock(var->rsrc[i].mtx);
		if (*var->rsrc[i].state == STATE_FREE)
		{
			*var->rsrc[i].state = var->id;
			pthread_mutex_unlock(var->rsrc[i].mtx);
			i++;
			if (i == var->param->n_thd && i < N_RESOURCE)
				return (soph_thread_main_loop_release(var, i));
		}
		else
		{
			pthread_mutex_unlock(var->rsrc[i].mtx);
			soph_thread_main_loop_release(var, i);
			usleep(TIME_TACK);
			i = 0;
		}
	}
	return (true);
}

static void	soph_thread_main_loop(t_var *var)
{
	long	ts;

	while (!soph_compare_turn_static(var, TURN_TERM))
	{
		if (!soph_thread_main_loop_book(var, N_RESOURCE))
			break ;
		soph_thread_main_loop_hold(var, N_RESOURCE);
		ts = soph_gettime();
		soph_setvar_ts_upd(var, ts);
		soph_print_log(ts, var->id, MSG_EXEC, var);
		soph_sleep_adjust(ts, ts + var->param->time_exec);
		soph_thread_main_loop_release(var, N_RESOURCE);
		ts = soph_gettime();
		soph_print_log(ts, var->id, MSG_SLEEP, var);
		soph_setvar_turn_incr(var);
		soph_sleep_adjust(ts, ts + var->param->time_sleep);
		soph_print_log(soph_gettime(), var->id, MSG_QUEUE, var);
		ts += var->param->time_sleep;
		soph_sleep_adjust(ts, ts + var->param->time_queue);
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
	soph_thread_main_loop(var);
	return (NULL);
}
