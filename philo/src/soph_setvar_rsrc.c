/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_setvar_rsrc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/26 22:40:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	*soph_setvar_rsrc_state(int n_thd)
{
	int		*states;
	ssize_t	i;

	states = (int *)malloc(n_thd * sizeof(int));
	if (states == NULL)
		return (NULL);
	i = 0;
	while (i < n_thd)
		states[i++] = STATE_FREE;
	return (states);
}

t_rsrc	*soph_setvar_rsrc(int n_thd)
{
	t_rsrc	*rsrc;
	int		*states;
	t_mtx	*mtx;
	ssize_t	i;

	rsrc = (t_rsrc *)malloc(n_thd * sizeof(t_rsrc));
	if (rsrc == NULL)
		return (NULL);
	states = soph_setvar_rsrc_state(n_thd);
	if (states == NULL)
	{
		free(rsrc);
		return (NULL);
	}
	mtx = soph_mutex_init(n_thd, NULL, rsrc);
	if (mtx == NULL)
		return (NULL);
	i = 0;
	while (i < n_thd)
	{
		rsrc[i].state = &states[i];
		rsrc[i].mtx = &mtx[i];
		i++;
	}
	return (rsrc);
}
