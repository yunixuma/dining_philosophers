/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_setvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/19 07:56:53 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_var	\
	*soph_setvar_each(t_var *var, t_param *param, t_rsrc *rsrc, t_mtx *mtx)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < param->n_thd)
	{
		var[i].id = i;
		var[i].param = param;
		j = 0;
		while (j < N_RESOURCE)
		{
			var[i].rsrc[j] = rsrc[(i + j) % param->n_thd];
			j++;
		}
		var[i].mtx = mtx;
		var[i].turn = 0;
		i++;
	}
	return (var);
}

t_var	*soph_setvar(t_param *param, t_rsrc *rsrc)
{
	t_var	*var;
	t_mtx	*mtx;

	var = (t_var *)malloc(param->n_thd * sizeof(t_var));
	if (var == NULL)
	{
		soph_clean(NULL, rsrc, NULL, param->n_thd);
		return (NULL);
	}
	mtx = soph_mutex_init(N_MUTEX, var, rsrc);
	if (mtx == NULL)
	{
		soph_clean(var, rsrc, NULL, param->n_thd);
		return (NULL);
	}
	soph_setvar_each(var, param, rsrc, mtx);
	return (var);
}

void	soph_setvar_turn_incr(t_var *var)
{
	pthread_mutex_lock(&var->mtx[IDX_LIMIT]);
	var->turn++;
	pthread_mutex_unlock(&var->mtx[IDX_LIMIT]);
}

void	soph_setvar_ts_upd(t_var *var, long ts)
{
	pthread_mutex_lock(&var->mtx[IDX_MONI]);
	var->ts_target = ts + var->param->timeout;
	pthread_mutex_unlock(&var->mtx[IDX_MONI]);
}
