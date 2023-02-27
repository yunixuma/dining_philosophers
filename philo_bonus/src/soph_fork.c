/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/22 04:15:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	soph_fork(t_var *var)
{
	pid_t	*pids;
	ssize_t	i;

	pids = (pid_t *)malloc(var->param->n_proc * sizeof(pid_t));
	if (pids == NULL)
		return (soph_clean_err(ERR_ALLOC, var->sems, NULL));
	var->ts_target = soph_gettime() + TIME_TACK;
	i = 0;
	while (i < var->param->n_proc)
	{
		var->id = i;
		pids[i] = fork();
		if (pids[i] == 0)
			return (soph_child(var, pids));
		else if (pids[i] < 0)
		{
			soph_kill(pids, i);
			return (soph_clean_err(ERR_FORK, var->sems, pids));
		}
		i++;
	}
	soph_parent(var->sems, pids, var->param->n_proc);
	return (ERR_NOERR);
}
