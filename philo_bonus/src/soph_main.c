/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/07 21:23:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_param	param;
	t_var	var;
	sem_t	**sems;

	errno = soph_argchk(argc, argv);
	if (errno)
		return (soph_print_err(errno));
	param = soph_setparam(argc, argv);
	sems = soph_sem_open_all(param.n_proc);
	if (sems == NULL)
		return (soph_print_err(errno));
	var = soph_setvar(&param, sems);
	errno = soph_fork(&var);
	if (errno)
		return (soph_print_err(errno));
	return (ERR_NOERR);
}
