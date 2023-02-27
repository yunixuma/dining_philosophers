/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_typedef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/08 00:43:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPEDEF_H
# define PHILO_TYPEDEF_H

typedef pthread_t	t_thd;

typedef struct s_param
{
	int		n_proc;
	int		timeout;
	int		time_exec;
	int		time_sleep;
	int		max_turn;
	int		time_queue;
}	t_param;

typedef struct s_var
{
	int		id;
	t_param	*param;
	sem_t	**sems;
	long	ts_target;
	int		turn;
}	t_var;

#endif
