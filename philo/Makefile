# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 19:27:22 by tchariss          #+#    #+#              #
#    Updated: 2021/07/29 19:27:23 by tchariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c utils.c check.c process.c 

OBJS = $(SRCS:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

norm : 
	norminette *.c

.PHONY: all clean fclean re norm