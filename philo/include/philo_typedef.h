/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_typedef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/19 07:46:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPEDEF_H
# define PHILO_TYPEDEF_H

typedef pthread_t		t_thd;
typedef pthread_mutex_t	t_mtx;

typedef struct s_param
{
	int		n_thd;
	int		timeout;
	int		time_exec;
	int		time_sleep;
	int		max_turn;
	int		time_queue;
}	t_param;

typedef struct s_rsrc
{
	int		*state;
	t_mtx	*mtx;
}	t_rsrc;

typedef struct s_var
{
	int		id;
	t_param	*param;
	t_rsrc	rsrc[N_RESOURCE];
	t_mtx	*mtx;
	long	ts_target;
	int		turn;
}	t_var;

#endif
