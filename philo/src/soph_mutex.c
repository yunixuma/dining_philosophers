/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/18 05:17:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mtx	*soph_mutex_init(int n_mtx, t_var *var, t_rsrc *rsrc)
{
	t_mtx	*mtx;
	ssize_t	i;

	mtx = (t_mtx *)malloc((n_mtx) * sizeof(t_mtx));
	if (mtx == NULL)
	{
		soph_clean(var, rsrc, NULL, 0);
		return (NULL);
	}
	i = 0;
	while (i < n_mtx)
	{
		errno = pthread_mutex_init(&(mtx[i++]), NULL);
		if (errno != ERR_NOERR)
		{
			soph_clean(NULL, rsrc, NULL, i);
			return (NULL);
		}
	}
	return (mtx);
}

void	soph_mutex_destroy(t_mtx *mtx, int n_mtx)
{
	ssize_t	i;

	i = 0;
	(void)n_mtx;
//	while (i < n_mtx)
		pthread_mutex_destroy(&(mtx[i++]));
pthread_mutex_destroy(&(mtx[i++]));
pthread_mutex_destroy(&(mtx[i++]));
	free(mtx);
}
