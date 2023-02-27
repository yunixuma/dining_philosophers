# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/01/16 15:07:07 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= philo_bonus

# Enumeration of files
SRC				= soph_main.c soph_argchk.c soph_setparam.c soph_setvar.c \
				  soph_sem.c soph_fork.c soph_parent.c soph_kill.c \
				  soph_child_thread.c soph_child_moni.c soph_clean.c \
				  soph_sleep.c \
				  soph_calc.c soph_compare.c soph_gettime.c soph_atoi.c \
				  ft_putstr_fd.c ft_strlcpy.c ft_strlcpy_nbr.c ft_memset.c \
				  ft_strncmp.c ft_strlen.c ft_isdigit.c
SRC_SAFE		= soph_child.c soph_print.c
SRC_FAST		= soph_child_fast.c soph_print_fast.c
SRC_DEBUG		= debug_soph.c
SRC_DEBUG_MAC	= debug_macos.c

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
OBJDIR			= ./obj

# Aliases of commands
CC				= cc
RM				= rm

# Check the platform
OS				= $(shell uname)

# Command options (flags)
CFLAGS			= -MMD -DNOLOCK -pthread -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer -fsanitize=thread
ifneq ($(OS), Darwin)
#	DEBUGCFLAGS	+= -fstack-usage
endif
#DEBUGLDFLAGS	= -fsanitize=address
OPTCFLAGS		= -O3 -march=native
OPTCFLAGS_FAST	= -Ofast -march=native
INCLUDES		= -I$(INCDIR)
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), fast)
	SRC				+= $(SRC_FAST)
	CFLAGS			+= $(OPTCFLAGS_FAST)
else
	SRC				+= $(SRC_SAFE)
	ifeq ($(MAKECMDGOALS), debug)
		ifeq ($(OS), Darwin)
			SRC		+= $(SRC_DEBUG_MAC)
		else
			SRC		+= $(SRC_DEBUG)
			LDFLAGS	+= $(DEBUGLDFLAGS)
		endif
		CFLAGS	+= $(DEBUGCFLAGS)
		DEF			= -D DEBUG_MODE=1
	else
		CFLAGS		+= $(OPTCFLAGS)
	endif
endif

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re fast debug

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
fast: fclean all
debug: fclean all

# Recipes
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(INCLUDES) -o $(NAME)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
