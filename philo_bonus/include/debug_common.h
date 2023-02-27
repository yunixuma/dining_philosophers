/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_common.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/10 12:34:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_COMMON_H
# define DEBUG_COMMON_H

# include <stdio.h>
# include <stdarg.h>
//# include "ft_printf.h"
# ifdef __MACH__
#  include "debug_macos.h"
# endif

# ifndef DEBUG_FILENO
#  define DEBUG_FILENO	2
# endif
# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
# endif

//int	debug_printf(const char *format, ...);
//int	debug_dummy(const char *format, ...);

#endif
