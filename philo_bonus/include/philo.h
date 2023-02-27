/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/16 15:05:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
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
t_var	soph_setvar(t_param *param, sem_t **sems);
void	soph_setvar_turn_incr(t_var *var);
void	soph_setvar_ts_upd(t_var *var, long ts);
sem_t	**soph_sem_open_all(int n_proc);
int		soph_sem_close(sem_t *sem);
int		soph_sem_unlink(const char *name);
int		soph_fork(t_var *var);
int		soph_parent(sem_t **sems, pid_t *pids, int n_proc);
int		soph_kill(pid_t *pids, int n_proc);
int		soph_child(t_var *var, pid_t *pids);
int		soph_child_thread_create(t_thd *thd, t_var *var);
int		soph_child_thread_join(t_thd *thd);
void	*soph_child_moni(void *p);
void	soph_print_log(long ts, int i_thd, const char *msg, t_var *var);
int		soph_print_err(int errnum);
int		soph_print_err_clean(int errnum, sem_t *sem, pid_t *pids);
void	soph_clean(sem_t **sems, pid_t *pids);
int		soph_clean_err(int errnum, sem_t **sems, pid_t *pids);
int		soph_clean_err(int errnum, sem_t **sems, pid_t *pids);
void	*soph_clean_err_null(int errnum, sem_t **sems, pid_t *pids);
void	soph_sleep_adjust(long ts_now, long ts_tgt);
int		soph_calc_queue(t_param *param);
int		soph_calc_preempt(t_var *var);
bool	soph_compare_ts_static(t_var *var, int ts_tgt);
bool	soph_compare_turn_static(t_var *var, int turn_tgt);
bool	soph_compare_turn_dynamic(t_var *var);
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
