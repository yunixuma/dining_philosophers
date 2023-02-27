/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/14 18:16:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_soph.h"

void	debug_soph_param(t_param param)
{
	if (DEBUG_MODE == 0)
		return ;
	dprintf(\
		DEBUG_FILENO, \
		"param\n\tn_thd:\t%3d\n\
	timeout:\t%3d\n\ttime_exec:\t%3d\n\ttime_sleep:\t%3d\n\
	time_queue:\t%3d\nmax_turn:\t%3d\n", \
		param.n_proc, \
		param.timeout, \
		param.time_exec, \
		param.time_sleep, \
		param.time_queue, \
		param.max_turn \
		);
}

void	debug_soph_var(t_var var)
{
	if (DEBUG_MODE == 0)
		return ;
	dprintf(\
		DEBUG_FILENO, \
		"var\tid: %d\tts_exec: %ld\tturn: %d\t", \
		var.id, \
		var.ts_target, \
		var.turn \
		);
	debug_soph_param(*var.param);
}

void	debug_soph_sem(sem_t *sem)
{
	if (DEBUG_MODE == 0)
		return ;
	if (sem == NULL)
		return ;
	dprintf(DEBUG_FILENO, "sems\t%%p: %p\n", sem);
}

void	debug_soph_pids(pid_t *pids, int n_proc)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (pids == NULL)
		return ;
	dprintf(DEBUG_FILENO, "pids\t%%p: %p\tn_proc: %d\n", pids, n_proc);
	i = 0;
	while (i < n_proc)
	{
		dprintf(DEBUG_FILENO, "\t%%pids[%zd]: %d\n", i, pids[i]);
		i++;
	}
}
