/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/22 06:44:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_param	param;
	t_rsrc	*rsrc;
	t_var	*var;
	t_thd	*thd;

	errno = soph_argchk(argc, argv);
	if (errno)
		return (soph_print_err(errno));
	param = soph_setparam(argc, argv);
	rsrc = soph_setvar_rsrc(param.n_thd);
	if (rsrc == NULL)
		return (soph_print_err(errno));
	var = soph_setvar(&param, rsrc);
	if (var == NULL)
		return (soph_print_err(errno));
	thd = soph_thread_init(param.n_thd, var, rsrc);
	if (thd == NULL)
		return (soph_print_err(errno));
	errno = soph_thread_create(thd, var, rsrc);
	if (errno)
		return (soph_print_err(errno));
	soph_moni(var);
	errno = soph_thread_join(thd, param.n_thd);
	soph_clean(var, rsrc, thd, param.n_thd);
	return (errno);
}
