/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/14 18:14:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_soph.h"

void	debug_soph_var(t_var var)
{
	if (DEBUG_MODE == 0)
		return ;
	dprintf(\
		DEBUG_FILENO, \
		"var\tid: %d\tts_exec: %ld\tturn: %d\t", \
		var.id, \
		var.ts_target, \
		var.turn \
		);
	debug_soph_param(*var.param);
}

void	debug_soph_vars(t_var *var)
{
	ssize_t	size;
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (var == NULL)
		return ;
	size = var[0].param->n_thd;
	dprintf(DEBUG_FILENO, "vars\t%%p: %p\tsize: %zd\n", var, size);
	i = 0;
	while (i < size)
	{
		dprintf(DEBUG_FILENO, "%3zd\t", i);
		debug_soph_var(var[i]);
		i++;
	}
}
