/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/06 23:29:57 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	soph_clean(sem_t **sems, pid_t *pids)
{
	if (sems)
	{
		if (sems[IDX_RSRC])
			soph_sem_unlink(NAME_RSRC);
		if (sems[IDX_IO])
			soph_sem_unlink(NAME_IO);
		if (sems[IDX_LIMIT])
			soph_sem_unlink(NAME_LIMIT);
		free(sems);
	}
	if (pids)
		free(pids);
}

int	soph_clean_err(int errnum, sem_t **sems, pid_t *pids)
{
	soph_clean(sems, pids);
	return (soph_print_err(errnum));
}

void	*soph_clean_err_null(int errnum, sem_t **sems, pid_t *pids)
{
	soph_clean(sems, pids);
	soph_print_err(errnum);
	errno = errnum;
	return (NULL);
}
