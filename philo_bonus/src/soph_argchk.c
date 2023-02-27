/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_argchk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/12 10:51:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	soph_argchk(int argc, char *argv[])
{
	int		num;
	ssize_t	i;

	if (argc < OFFSET_ARG + IDX_ARG_TIME_SLEEP \
		|| argc > OFFSET_ARG + IDX_ARG_MAX_TURN)
		return (ERR_ARG);
	i = OFFSET_ARG;
	while (i < argc)
	{
		num = soph_atoi(argv[i]);
		if (num <= 0)
			return (ERR_NUM);
		else if (num <= TIME_TACK / UNIT_TIME \
			&& IDX_ARG_N_THREAD < i && i < IDX_ARG_MAX_TURN)
			return (ERR_TIME);
		i++;
	}
	return (ERR_NOERR);
}
