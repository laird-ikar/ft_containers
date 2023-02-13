# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:33:27 by bguyot            #+#    #+#              #
#    Updated: 2023/02/10 17:14:46 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: benchmark 

benchmark:	tests
	./test.sh

tests: vector_assign

vector_assign:  tests/vector_assign.cpp
	$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_assign tests/vector_assign.cpp
	$(CC) $(CFLAGS) -D VAL -o test_std_vector_assign tests/vector_assign.cpp
	$(CC) $(CFLAGS) -D FT -o test_ft_vector_assign_it tests/vector_assign.cpp
	$(CC) $(CFLAGS) -o test_std_vector_assign_it tests/vector_assign.cpp

clean:
	rm -f test_ft_vector_assign
	rm -f test_std_vector_assign
	rm -f test_ft_vector_assign_it
	rm -f test_std_vector_assign_it