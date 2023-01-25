# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:39:40 by aqueiroz          #+#    #+#              #
#    Updated: 2023/01/25 11:37:27 by aqueiroz         ###   ########.fr        #
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

SRC_PATH = srcs
LIB_PATH = libs
OBJ_PATH = objs
PATH_INC = includes
LIBFT_PATH = $(LIB_PATH)/libft
FT_PRINTF_PATH = $(LIB_PATH)/printf
LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

FILES= main parse_map validators utils

SRCS = $(addprefix $(PATH_SRC)/, $(addsuffix .c, $(FILES)))
OBJS = $(addsuffix .o, $(FILES))

# FLAGS

CC = cc
CFLAGS = 
LIBFLAGS = -L./$(LIBFT_PATH) -L./$(FT_PRINTF_PATH) -lft -lftprintf -lXext -lX11 -lmlx -lm

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ_PATH) $(OBJS)
	@$(CC) -g3 $(addprefix $(OBJ_PATH)/,$(OBJS)) $(LIBFLAGS) -o $@
	$(info $(purple)All installed. Run './fdf' with a map as argument.$(reset))

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c -I $(PATH_INC) -o $(OBJ_PATH)/$@ $<
	
$(LIBFT):
ifeq ($(shell mkdir -p libs && cd libs && ls | grep libft), libft)
	$(info $(blue)Compiling libft.$(reset))
	@$(MAKE) -s -k -C $(LIBFT_PATH)
	$(info $(green)Libft installed!$(reset))
endif

$(FT_PRINTF):
ifeq ($(shell mkdir -p libs && cd libs && ls | grep printf), printf)
	$(info $(blue)Compiling printf.$(reset))
	@$(MAKE) -s -k -C $(FT_PRINTF_PATH)
	$(info $(green)Printf installed!$(reset))
endif
	$(info $(yellow)Compiling fdf.$(reset))

valgrind:
	valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) /maps/42.fdf
clean:
	@rm -dfr ./objs
	@$(MAKE) -C $(FT_PRINTF_PATH) --silent clean
	@$(MAKE) -C $(LIBFT_PATH) --silent clean
	$(info $(yellow)All libs files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_PATH) --silent clean
	@$(MAKE) -C $(LIBFT_PATH) --silent clean
	$(info $(yellow)Fdf file was removed.$(reset))

re: fclean all
	
.PHONY: all color-test clean fclean re