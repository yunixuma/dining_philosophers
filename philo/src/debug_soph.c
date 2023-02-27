/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/19 07:54:43 by Yoshihiro K      ###   ########.fr       */
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
		param.n_thd, \
		param.timeout, \
		param.time_exec, \
		param.time_sleep, \
		param.time_queue, \
		param.max_turn \
		);
}

void	debug_soph_mtxs(t_mtx *mtx, int n_thd)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (mtx == NULL)
		return ;
	dprintf(DEBUG_FILENO, "mtxs\t%%p: %p\tn_thd: %d\n", mtx, n_thd);
	i = 0;
	while (i < n_thd)
	{
		dprintf(DEBUG_FILENO, "\tmtx[%zd]: %d\n", i, mtx[i].__data.__owner);
		i++;
	}
}

void	debug_soph_rsrcs(t_rsrc *rsrc)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (rsrc == NULL)
		return ;
	dprintf(DEBUG_FILENO, "rsrcs\t%%p: %p\tn_thd: %d\n", rsrc, N_RESOURCE);
	i = 0;
	while (i < N_RESOURCE)
	{
		dprintf(DEBUG_FILENO, "\trsrc[%zd]\tstate: %d\tmtx: %d\n", \
			i, *rsrc[i].state, rsrc[i].mtx->__data.__owner);
		i++;
	}
}

void	debug_soph_thds(t_thd *thd, int n_thd)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (thd == NULL)
		return ;
	dprintf(DEBUG_FILENO, "thds\t%%p: %p\tn_thd: %d\n", thd, n_thd);
	i = 0;
	while (i < n_thd)
	{
		dprintf(DEBUG_FILENO, "\t%%thd[%zd]: %ld\n", i, thd[i]);
		i++;
	}
}
