/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/30 10:38:22 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_SOPH_H
# define DEBUG_SOPH_H

# include "debug_common.h"
# include "philo.h"

void	debug_soph_param(t_param param);
void	debug_soph_var(t_var var);
void	debug_soph_vars(t_var *var);
void	debug_soph_mtxs(t_mtx *mtx, int n_thd);
void	debug_soph_rsrcs(t_rsrc *rsrc);
void	debug_soph_thds(t_thd *thd, int n_thd);
void	debug_soph_test(t_var *var);

#endif
