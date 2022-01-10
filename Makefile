# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 17:07:58 by wiozsert          #+#    #+#              #
#    Updated: 2022/01/10 14:10:12 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -Wall -Wextra -Werror
SRCS = $(shell find . -name "*.c")
OBJ = $(addsuffix .o, $(notdir $(basename $(SRCS))))

all : $(NAME)

$(NAME) : $(SRCS)
	mkdir -p obj
	$(CC) $(FLAGS) -c $(SRCS) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	mv $(OBJ) ./obj

clean :
	rm -Rf ./obj $(OBJ)

fclean : clean
	rm -Rf $(NAME)

re : fclean all
