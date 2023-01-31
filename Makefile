# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:58:54 by bguyot            #+#    #+#              #
#    Updated: 2023/01/30 14:46:15 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

FILES		=			\
	tester

SRC_DIR		=			src/tester/
SRC_FIL		=			$(FILES)
SRCS		=			$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))

OBJS		=			$(SRCS:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-std=c++98

$(NAME): ft_tester std_tester

ft_tester: $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o ft_tester $(OBJS)

std_tester: $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o std_tester $(OBJS)

%.o: %.cpp %.hpp
	@printf "\e[36m\033[2K\r\t\t"$@"\e[39m"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<