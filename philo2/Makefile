# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 10:42:30 by wiozsert          #+#    #+#              #
#    Updated: 2022/02/23 18:59:23 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -Wall -Wextra -Werror -pthread -g3
#-fsanitize=address
-fsanitize=thread
# SRCS = ./srcs/philo.c
SRCS = $(shell find . -name "*.c")

OBJ = $(addsuffix .o, $(notdir $(basename $(SRCS))))

all : $(NAME)

$(NAME) : $(SRCS)
	mkdir -p obj
	$(CC) $(FLAGS) -c $(SRCS) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	mv $(OBJ) ./obj

clean :
	rm -Rf ./obj

fclean : clean
	rm -Rf $(NAME)

re : fclean all