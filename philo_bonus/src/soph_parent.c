/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/22 04:53:22 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	soph_parent_wait(int n_proc)
{
	int		status;
	ssize_t	i;

	i = 0;
	while (i < n_proc)
	{
		waitpid(PID_CHILD, &status, WCONTINUED);
		if (status)
			return (status);
		i++;
	}
	return (ERR_NOERR);
}

int	soph_parent(sem_t *sem[], pid_t *pids, int n_proc)
{
	if (soph_parent_wait(n_proc) != ERR_NOERR)
		soph_kill(pids, n_proc);
	soph_clean(sem, pids);
	return (ERR_NOERR);
}
