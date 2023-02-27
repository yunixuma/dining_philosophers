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

void	soph_sleep_adjust(long ts_now, long ts_tgt)
{
	if (ts_tgt > ts_now + TIME_TACK)
		usleep(ts_tgt - ts_now - TIME_TACK);
	while (soph_gettime() < ts_tgt)
		usleep(TIME_TICK);
}
