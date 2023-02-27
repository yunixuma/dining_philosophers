/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/04 18:49:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	soph_clean(t_var *var, t_rsrc *rsrc, t_thd *thd, int n_thd)
{
	if (var)
	{
		if (var->mtx)
			soph_mutex_destroy(var->mtx, N_MUTEX);
		free(var);
	}
	if (rsrc)
	{
		if (rsrc[0].mtx)
			soph_mutex_destroy(rsrc[0].mtx, n_thd);
		if (rsrc[0].state)
			free(rsrc[0].state);
		free(rsrc);
	}
	if (thd)
		free(thd);
	return ;
}
