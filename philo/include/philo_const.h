/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/18 13:04:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

# include <limits.h>

# ifndef N_RESOURCE
#  define N_RESOURCE		2
# endif

# define OFFSET_ARG			1
# define IDX_ARG_N_THREAD	1
# define IDX_ARG_TIMEOUT	2
# define IDX_ARG_TIME_EXEC	3
# define IDX_ARG_TIME_SLEEP	4
# define IDX_ARG_MAX_TURN	5
# define IDX_IO				0
# define IDX_LIMIT			1
# define IDX_MONI			2
# define N_MUTEX			3
# define MAX_RECURSE		20
# define ERR_NOERR			0
# define ERR_ARG			EINVAL
# define ERR_NUM			EDOM
# define ERR_TIME			ERANGE
# define ERR_ALLOC			ENOMEM
# define ERR_RSRC			EAGAIN
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
