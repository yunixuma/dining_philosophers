/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/19 04:49:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <errno.h>
# include "philo_const.h"
# include "philo_string.h"
# include "philo_typedef.h"
# ifdef DEBUG_MODE
#  ifndef __MACH__
#   include "debug_soph.h"
#  endif
# endif

int		main(int argc, char *argv[]);
int		soph_argchk(int argc, char *argv[]);
t_param	soph_setparam(int argc, char *argv[]);
t_rsrc	*soph_setvar_rsrc(int n_thd);
t_var	*soph_setvar(t_param *param, t_rsrc *rsrc);
void	soph_setvar_turn_incr(t_var *var);
void	soph_setvar_ts_upd(t_var *var, long ts);
t_mtx	*soph_mutex_init(int n_thd, t_var *var, t_rsrc *rsrc);
void	soph_mutex_destroy(t_mtx *mtx, int n_thd);
t_thd	*soph_thread_init(int n_thd, t_var *var, t_rsrc *rsrc);
int		soph_thread_create(t_thd *thd, t_var *var, t_rsrc *rsrc);
int		soph_thread_join(t_thd *thd, int n_thd);
int		soph_thread_detach(t_thd *thd, int n_thd);
void	*soph_thread_main(void *p);
void	soph_moni(t_var *var);
int		soph_print_err(int errnum);
void	soph_print_log(long ts, int i_thd, const char *msg, t_var *var);
void	soph_clean(t_var *var, t_rsrc *rsrc, t_thd *thd, int n_thd);
void	soph_sleep_adjust(long ts_now, long ts_tgt);
int		soph_calc_queue(t_param *param);
long	soph_calc_preempt(t_var *var);
bool	soph_compare_ts_static(t_var *var, int ts_tgt);
bool	soph_compare_turn_static(t_var *var, int turn_tgt);
bool	soph_compare_turn_dynamic(t_var *var, int id);
long	soph_gettime(void);
int		soph_atoi(const char *str);
void	soph_putnbr_fd(long nb, int fd);
char	*ft_ulltostr(unsigned long long ui);
size_t	ft_strlcpy_nbr(char *str, long long nbr, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *buf, int ch, size_t n);
ssize_t	ft_putstr_fd(const char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

#endif
