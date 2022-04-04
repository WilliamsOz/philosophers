# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 10:42:30 by wiozsert          #+#    #+#              #
#    Updated: 2022/04/04 13:19:49 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread
#-fsanitize=address

SRCS = ./srcs/thread/print_status.c ./srcs/thread/init_thread.c \
./srcs/thread/routine.c ./srcs/dlk/destroy_dlk.c ./srcs/dlk/init_dlk.c \
./srcs/errors/is_emty.c ./srcs/errors/greater_than_integer.c \
./srcs/errors/errors.c ./srcs/errors/not_integer.c ./srcs/mutex/init_mutex.c \
./srcs/time/get_time.c ./srcs/utils/ft_atol.c ./srcs/utils/print_fd.c \
./srcs/utils/ft_strlen.c ./srcs/utils/ft_atoi.c ./srcs/philo.c \
./srcs/data/destroy_data.c ./srcs/data/init_data.c \

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