# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shedelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 15:55:24 by shedelin          #+#    #+#              #
#    Updated: 2014/01/03 15:55:26 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
CC=gcc
FLAGS=-Wall -Werror -Wextra -I/usr/X11/include/
FLAGSMLX =-L/usr/X11/lib -lmlx -lXext -lX11 
LIB=libft/
HEADER=includes/
SRC=main.c \
	w3_get_map.c \
	w3_raycasting.c \
	w3_error.c \
	w3_draw.c \
	w3_mlx.c \
	w3_move.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@$(CC) $(FLAGSMLX) $(FLAGS) -o $(NAME) $^ -I. -I$(LIB)$(HEADER) -L$(LIB) -lft
	@echo "\033[1;32mWOLF3D OK\033[0m"

%.o: %.c
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I. -I$(LIB)$(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB) $@
	@rm -f $(NAME)

re: fclean all