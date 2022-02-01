# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 17:07:58 by wiozsert          #+#    #+#              #
#    Updated: 2022/02/01 13:59:31 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread
SRCS = ./srcs/data/init_data.c ./srcs/data/get_starting_time.c \
./srcs/data/get_data.c ./srcs/data/data_destroyer.c ./srcs/time/get_time.c \
./srcs/utils/ft_atol.c ./srcs/utils/destroyer.c ./srcs/utils/ft_strlen.c \
./srcs/utils/ft_atoi.c ./srcs/utils/print_fd.c ./srcs/philo.c \
./srcs/errors/is_emty.c ./srcs/errors/greater_than_integer.c \
./srcs/errors/errors.c ./srcs/errors/not_integer.c ./srcs/philo/manager.c \
./srcs/philo/wait_threads.c ./srcs/philo/print_status.c \
./srcs/philo/child/is_it_end.c ./srcs/philo/child/routine.c \
./srcs/philo/child/childs_routine.c ./srcs/philo/child/init_childs.c \
./srcs/dlk/get_philo_id.c ./srcs/dlk/get_last_node.c ./srcs/dlk/init_dlk.c \
./srcs/dlk/dlk_destroyer.c

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