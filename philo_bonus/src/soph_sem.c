/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_sem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/04 09:26:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static sem_t	*soph_sem_open(const char *name, int n_proc)
{
	sem_t	*sem;

	soph_sem_unlink(name);
	sem = sem_open(name, O_CREAT, FLAG_MODE, n_proc);
	return (sem);
}

sem_t	**soph_sem_open_all(int n_proc)
{
	sem_t	**sems;

	sems = (sem_t **)malloc(N_SEM * sizeof(sem_t *));
	if (sems == NULL)
		soph_clean_err_null(ERR_ALLOC, sems, NULL);
	memset(sems, 0x00, N_SEM * sizeof(sem_t *));
	sems[IDX_RSRC] = soph_sem_open(NAME_RSRC, n_proc);
	if (sems[IDX_RSRC] == NULL)
		soph_clean_err_null(ERR_SEM, sems, NULL);
	sems[IDX_IO] = soph_sem_open(NAME_IO, MAX_IO);
	if (sems[IDX_IO] == NULL)
		soph_clean_err_null(ERR_SEM, sems, NULL);
	sems[IDX_LIMIT] = soph_sem_open(NAME_LIMIT, 1);
	if (sems[IDX_LIMIT] == NULL)
		soph_clean_err_null(ERR_SEM, sems, NULL);
	sems[IDX_MONI] = soph_sem_open(NAME_MONI, 1);
	if (sems[IDX_MONI] == NULL)
		soph_clean_err_null(ERR_SEM, sems, NULL);
	return (sems);
}

int	soph_sem_close(sem_t *sem)
{
	return (sem_close(sem));
}

int	soph_sem_unlink(const char *name)
{
	return (sem_unlink(name));
}
