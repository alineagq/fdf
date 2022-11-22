# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:39:40 by aqueiroz          #+#    #+#              #
#    Updated: 2022/11/18 03:50:00 by aqueiroz         ###   ########.fr        #
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

color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# PATH AND FILES

NAME=fdf

SRC_PATH=./srcs/
LIB_PATH=./libs/
OBJ_PATH=./objs/
PATH_INC=./includes/
LIBFT_PATH=./libs/libft
FT_PRINTF_PATH=./libs/ft_printf
MLX_PATH=./libs/mlx-linux
LIBS_PATH	=	-L$(LIBFT_PATH) -L$(MLX_PATH) -L$(FT_PRINTF_PATH)

FILES= main render_map
SRCS = $(addprefix $(PATH_SRC), $(addsuffix .c, $(FILES)))
OBJS = $(addsuffix .o, $(FILES))

# FLAGS

CC=cc
INCLUDES=-I $(PATH_INC) -I $(LIBFT_PATH)/includes -I $(FT_PRINTF_PATH) -I $(MLX_PATH)
CFLAGS=-Wall -Werror -Wextra $(INCLUDES)
LIBS=-lX11 -lXext -Imlx -lXext
CFLAGS_MLX=-I /usr/include 

all: mlx libft printf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(addprefix ./objs/, $(OBJS)) -o $(NAME) $(LIBS_PATH) $(LIBS)
	$(info $(purple)All installed. Run './fdf' with a map as argument.$(reset))

%.o: srcs/%.c
	@mkdir -p objs 
	$(CC) $(CFLAGS) $(LIBS_PATH) $(LIBS) $< -o $(OBJ_PATH)$@
mlx:
	$(info $(yellow)WAIT: Gathering all necessary files.$(reset))
ifeq ($(shell mkdir -p libs && cd libs && ls | grep mlx), mlx)
	$(info $(green)Minilibx founded!$(reset))
else
	$(info $(blue)Cloning minilibx to libs folder.$(reset))
	@git clone --quiet https://github.com/42Paris/minilibx-linux.git $(LIB_PATH)mlx
	$(info $(blue)Compiling minilibx.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)mlx CFLAG=$(CFLAGS_MLX)
	$(info $(green)Minilibx installed!$(reset))
endif

libft:
ifeq ($(shell mkdir -p libs && cd libs && ls | grep libft), libft)
	$(info $(green)Libft founded!$(reset))
else
	$(info $(blue)Cloning Libft to libs folder.$(reset))
	@git clone --quiet git@github.com:alineagq/Libft.git $(LIB_PATH)libft
	$(info $(blue)Compiling libft.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)libft
	$(info $(green)Libft installed!$(reset))
endif

printf:
ifeq ($(shell mkdir -p libs && cd libs && ls | grep printf), printf)
	$(info $(green)Printf founded!$(reset))
else
	$(info $(blue)Cloning Printf to libs folder.$(reset))
	@git clone --quiet git@github.com:alineagq/ft_printf.git $(LIB_PATH)printf
	$(info $(blue)Compiling printf.$(reset))
	@$(MAKE) -s -k -C $(LIB_PATH)printf
	$(info $(green)Printf installed!$(reset))
endif
	$(info $(yellow)Compiling fdf.$(reset))

clean:
	@rm -dfr ./libs/ ./objs
	$(info $(yellow)All libs files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	$(info $(yellow)Fdf file was removed.$(reset))

re: fclean all
	
.PHONY: all color-test clean fclean re