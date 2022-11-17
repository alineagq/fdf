# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:39:40 by aqueiroz          #+#    #+#              #
#    Updated: 2022/11/17 00:37:05 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color-teste:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# FLAGS AND PATHS

SRC_PATH=./srcs/
LIB_PATH=./libs/
OBJ_PATH=./objs/

CC=cc
CFLAGS= 

all: mlx libft printf

mlx:
	@mkdir -p libs
	$(info $(yellow)WAIT: Gathering all necessary files.$(reset))
ifeq ($(shell cd libs && ls | grep  mlx), mlx)
	$(info $(green)Minilibx founded!$(reset))
else
	$(info $(blue)Cloning minilibx to libs folder.$(reset))
	@git clone --quiet https://github.com/42Paris/minilibx-linux.git $(LIB_PATH)mlx
	$(info $(blue)Compiling minilibx.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)mlx
	$(info $(green)Minilibx installed!$(reset))
endif

libft:
ifeq ($(shell cd libs && ls | grep  libft), libft)
	$(info $(green)Libft founded!$(reset))
else
	$(info $(blue)Cloning Libft to libs folder.$(reset))
	@git clone --quiet git@github.com:alineagq/Libft.git $(LIB_PATH)libft
	$(info $(blue)Compiling libft.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)libft
	$(info $(green)Libft installed!$(reset))
endif

printf:
ifeq ($(shell cd libs && ls | grep  printf), printf)
	$(info $(green)Printf founded!$(reset))
else
	$(info $(blue)Cloning Printf to libs folder.$(reset))
	@git clone --quiet git@github.com:alineagq/ft_printf.git $(LIB_PATH)printf
	$(info $(blue)Compiling printf.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)printf
	$(info $(green)Printf installed!$(reset))
endif
	$(info $(purple)All installed run './fdf' with a map as argument.$(reset))

clean:
	@rm -dfr ./libs/
	@rm -dfr ./srcs/*.o
	$(info $(yellow)All libs files were removed.$(reset))