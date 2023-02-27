/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/16 11:03:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

# include <limits.h>

# define OFFSET_ARG			1
# define IDX_ARG_N_THREAD	1
# define IDX_ARG_TIMEOUT	2
# define IDX_ARG_TIME_EXEC	3
# define IDX_ARG_TIME_SLEEP	4
# define IDX_ARG_MAX_TURN	5
# define IDX_RSRC			0
# define IDX_IO				1
# define IDX_LIMIT			2
# define IDX_MONI			3
# define N_SEM				4
# define N_RESOURCE			2
# define MAX_IO				1
# define MAX_RECURSE		20
# define ERR_NOERR			0
# define ERR_ARG			EINVAL
# define ERR_NUM			EDOM
# define ERR_TIME			ERANGE
# define ERR_ALLOC			ENOMEM
# define ERR_SEM			ENOENT
# define ERR_FORK			EAGAIN
# define ERR_TIMEOUT		ETIMEDOUT
# define PID_CHILD			-1
# define FLAG_MODE			0600
# define LEN_LOG			64
# define LEN_LLONG			21
# define LEN_ID				4
# define LEN_TS				5
# define LEN_MSG			20
# define LEN_DELIM			1
# define CHR_PAD			' '
# define STATE_FREE			-1
# define TURN_INF			INT_MIN
# define TURN_TERM			0
# define TURN_TIMEOUT		-1
# define UNIT_TIME			1000
# define TIME_ZERO			0
# define TIME_TICK			100
# define TIME_TACK			10000

#endif
