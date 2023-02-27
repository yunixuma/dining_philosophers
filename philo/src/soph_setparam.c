/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_setparam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/05 01:05:44 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	soph_setparam(int argc, char *argv[])
{
	t_param	param;

	param.n_thd = soph_atoi(argv[IDX_ARG_N_THREAD]);
	param.timeout = soph_atoi(argv[IDX_ARG_TIMEOUT]) * UNIT_TIME;
	param.time_exec = soph_atoi(argv[IDX_ARG_TIME_EXEC]) * UNIT_TIME;
	param.time_sleep = soph_atoi(argv[IDX_ARG_TIME_SLEEP]) * UNIT_TIME;
	if (argc == OFFSET_ARG + IDX_ARG_MAX_TURN)
		param.max_turn = soph_atoi(argv[IDX_ARG_MAX_TURN]);
	else
		param.max_turn = TURN_INF;
	param.time_queue = soph_calc_queue(&param);
	return (param);
}
