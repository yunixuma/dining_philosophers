/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/22 06:43:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thd	*soph_thread_init(int n_thd, t_var *var, t_rsrc *rsrc)
{
	t_thd	*thd;

	thd = (t_thd *)malloc(n_thd * sizeof(t_thd));
	if (thd == NULL)
	{
		soph_clean(var, rsrc, NULL, n_thd);
		return (NULL);
	}
	return (thd);
}

int	soph_thread_create(t_thd *thd, t_var *var, t_rsrc *rsrc)
{
	long	ts;
	ssize_t	i;

	ts = soph_gettime() + TIME_TACK;
	i = 0;
	while (i < var[0].param->n_thd)
	{
		var[i].ts_target = ts;
		errno = pthread_create(&thd[i], NULL, soph_thread_main, &(var[i]));
		if (errno)
		{
			soph_thread_detach(thd, var[0].param->n_thd);
			soph_clean(var, rsrc, thd, var[0].param->n_thd);
			return (errno);
		}
		i++;
	}
	return (ERR_NOERR);
}

int	soph_thread_join(t_thd *thd, int n_thd)
{
	int		errno_tmp;
	ssize_t	i;

	i = 0;
	while (i < n_thd)
	{
		errno_tmp = pthread_join(thd[i++], NULL);
		if (errno_tmp != ERR_NOERR && errno == ERR_NOERR)
			errno = errno_tmp;
	}
	return (errno);
}

int	soph_thread_detach(t_thd *thd, int n_thd)
{
	int		errno_tmp;
	ssize_t	i;

	i = 0;
	while (i < n_thd)
	{
		errno_tmp = pthread_detach(thd[i++]);
		if (errno_tmp != ERR_NOERR && errno == ERR_NOERR)
			errno = errno_tmp;
	}
	return (errno);
}
