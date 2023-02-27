/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/10 12:46:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRING_H
# define PHILO_STRING_H

# define STR_INTMAX		"2147483647"
# define STR_LLONGMIN	"-9223372036854775808"
# define STR_SPACE		"   "
# define MSG_ERR		"Error: "
# define MSG_ARG		"Number of arguments must be between 4 and 5\n"
# define MSG_NUM		"All arguments must be natural numbers\n"
# define MSG_TIME		"The time value you chose is too little\n"
# define MSG_ALLOC		"Failed to allocate memory\n"
# define MSG_RSRC		"Resource temporarily unavailable\n"
# define MSG_USAGE		"Usage: ./philo* $A $B $C $D [$E]\n"
# define MSG_ARG_A		"$A = number_of_philosophers\n"
# define MSG_ARG_B		"$B = time_to_die\n"
# define MSG_ARG_C		"$C = time_to_eat\n"
# define MSG_ARG_D		"$D = time_to_sleep\n"
# define MSG_ARG_E		"$E = number_of_times_each_philosopher_must_eat\n"
# define MSG_HOLD		" has taken a fork\n"
# define MSG_EXEC		" is eating\n"
# define MSG_SLEEP		" is sleeping\n"
# define MSG_QUEUE		" is thinking\n"
# define MSG_TIMEOUT	" died\n"
# define MSG_LOG		"%'ld%*d%s"

#endif
