# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 22:39:05 by brattles          #+#    #+#              #
#    Updated: 2022/03/21 19:43:18 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= gnl

CC			:= gcc
WFLAGS		:= -Wall -Wextra -Werror

OBJ_DIR		:= build

FUNCTIONS	= main.c \
			  get_next_line.c \
			  get_next_line_utils.c

OBJ			:= $(FUNCTIONS:%.c=$(OBJ_DIR)/%.o)
DEP			:= $(OBJ:%.o=%.d)
CFLAGS		:= $(WFLAGS) -MMD

INC			:= -I.

vpath %.c src

.PHONY:	all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all