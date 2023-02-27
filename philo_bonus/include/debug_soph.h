/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/07 02:38:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_SOPH_H
# define DEBUG_SOPH_H

# include "debug_common.h"
# include "philo.h"

void	debug_soph_param(t_param param);
void	debug_soph_var(t_var var);
void	debug_soph_sem(sem_t *sem);
void	debug_soph_pids(pid_t *pid, int n_proc);

#endif
