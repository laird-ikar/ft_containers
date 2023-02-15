# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:33:27 by bguyot            #+#    #+#              #
#    Updated: 2023/02/15 17:52:26 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: benchmark clean

benchmark:	tests
	@./test.sh

tests: vector_assign vector_insert vector_erase 

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

vector_erase:  tests/vector_erase.cpp
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_erase_it tests/vector_erase.cpp
	@$(CC) $(CFLAGS) -o test_std_vector_erase_it tests/vector_erase.cpp
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_erase tests/vector_erase.cpp
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_erase tests/vector_erase.cpp

vector_resize_reserve:  tests/vector_resize_reserve.cpp
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_resize tests/vector_resize_reserve.cpp
	@$(CC) $(CFLAGS) -o test_std_vector_resize tests/vector_resize_reserve.cpp
	@$(CC) $(CFLAGS) -D FT -D SIZE -o test_ft_vector_reserve tests/vector_resize_reserve.cpp
	@$(CC) $(CFLAGS) -o -D SIZE test_std_vector_reserve tests/vector_resize_reserve.cpp

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
	@rm -f test_ft_vector_erase_it
	@rm -f test_std_vector_erase_it
	@rm -f test_ft_vector_erase
	@rm -f test_std_vector_erase
