/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_soph_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/14 18:14:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_soph.h"

static void	debug_soph_test_write(size_t i_max)
{
	char	s[LEN_LOG];
	size_t	i;
	size_t	j;
	size_t	len;

	ft_strlcpy(s, MSG_HOLD, LEN_LOG);
	len = ft_strlen(s);
	i = 0;
	printf("%lu\tbefore\twrite\t%zu\n", soph_gettime(), i_max);
	while (i < i_max)
	{
		j = 0;
		while (j < len)
			write(DEBUG_FILENO, s + j++, 1);
		i++;
	}
	printf("%lu\tafter\twrite\t%zu\n", soph_gettime(), i_max);
}

static void	debug_soph_test_puts(size_t i_max)
{
	char	s[LEN_LOG];
	size_t	i;

	i = 0;
	printf("%lu\tbefore\tputs\t%zu\n", soph_gettime(), i_max);
	while (i < i_max)
	{
		ft_strlcpy(s, MSG_HOLD, LEN_LOG);
		ft_putstr_fd(s, DEBUG_FILENO);
		i++;
	}
	printf("%lu\tafter\tputs\t%zu\n", soph_gettime(), i_max);
}

static void	debug_soph_test_lock(t_var *var, size_t i_max)
{
	size_t	i;

	i = 0;
	printf("%lu\tbefore\tmutex\t%zu\n", soph_gettime(), i_max);
	while (i < i_max)
	{
		pthread_mutex_lock(var->rsrc[N_RESOURCE - 1].mtx);
		pthread_mutex_unlock(var->rsrc[N_RESOURCE - 1].mtx);
		i++;
	}
	printf("%lu\tafter\tmutex\t%zu\n", soph_gettime(), i_max);
}

static void	debug_soph_test_malloc(size_t i_max)
{
	char	*s;
	size_t	i;

	i = 0;
	printf("%lu\tbefore\tmalloc\t%zu\n", soph_gettime(), i_max);
	while (i < i_max)
	{
		s = (char *)malloc(LEN_LOG * sizeof(char));
		free(s);
		i++;
	}
	printf("%lu\tafter\tmalloc\t%zu\n", soph_gettime(), i_max);
}

void	debug_soph_test(t_var *var)
{
	size_t	i_max;

	i_max = 100000000;
	debug_soph_test_lock(var, i_max);
	debug_soph_test_malloc(i_max);
	i_max = 1000000;
	debug_soph_test_write(i_max);
	debug_soph_test_puts(i_max);
}
