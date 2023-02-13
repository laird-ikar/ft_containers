# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:33:27 by bguyot            #+#    #+#              #
#    Updated: 2023/02/13 18:03:21 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: benchmark 

benchmark:	tests
	./test.sh

tests: vector_assign vector_insert

vector_assign:  tests/vector_assign.cpp
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_assign tests/vector_assign.cpp
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_assign tests/vector_assign.cpp
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_assign_it tests/vector_assign.cpp
	@$(CC) $(CFLAGS) -o test_std_vector_assign_it tests/vector_assign.cpp

vector_insert:  tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_insert tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_insert tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -D N -D FT -o test_ft_vector_insert_n tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -D N -o test_std_vector_insert_n tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_insert_it tests/vector_insert.cpp
	@$(CC) $(CFLAGS) -o test_std_vector_insert_it tests/vector_insert.cpp

clean:
	@rm -f test_ft_vector_assign
	@rm -f test_std_vector_assign
	@rm -f test_ft_vector_assign_it
	@rm -f test_std_vector_assign_it
	@rm -f test_ft_vector_insert
	@rm -f test_std_vector_insert
	@rm -f test_ft_vector_insert_n
	@rm -f test_std_vector_insert_n
	@rm -f test_ft_vector_insert_it
	@rm -f test_std_vector_insert_it