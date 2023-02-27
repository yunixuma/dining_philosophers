/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/11 14:18:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	soph_kill(pid_t *pids, int n_proc)
{
	ssize_t	i;

	i = 0;
	while (i < n_proc)
		kill(pids[i++], SIGTERM);
	return (errno);
}
