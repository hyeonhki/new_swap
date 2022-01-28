# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 11:32:35 by hyeonhki          #+#    #+#              #
#    Updated: 2022/01/29 00:15:58 by hyeonhki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= main.c stack.c \
			utils.c error.c \
			operator.c operator_two.c \
			sort.c q_sort.c sort2.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I -fsanitize=address

all	: 	$(NAME)

$(NAME)	: 	$(OBJS)
		cc $(OBJS) $(CFLAGS) -o $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY :	all clean fclean re