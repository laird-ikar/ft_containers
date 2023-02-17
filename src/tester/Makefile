# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:33:27 by bguyot            #+#    #+#              #
#    Updated: 2023/02/17 13:31:13 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: benchmark clean

benchmark:	compiling vector

compiling:
	@printf "\e[36mJe compile att\e[39m"

compiling_end:
	@printf "\e[36m\033[2K\r\t"⊙"\t"Tests\ successfully\ compiled\ !"\n\e[39m"

vector: tests_vector compiling_end
	@./benchmark.sh

tests_vector: vector_assign vector_insert vector_erase vector_resize_reserve vector_egal vector_construct

vector_assign:  tests/vector_assign.cpp
	@printf "\e[36m\n\t"◜"\t"test_ft_vector_assign"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_assign tests/vector_assign.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_assign"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_assign tests/vector_assign.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_assign_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_assign_it tests/vector_assign.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_assign_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_assign_it tests/vector_assign.cpp

vector_insert:  tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◜"\t"test_ft_vector_insert"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_insert tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_insert"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_insert tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_insert_n"\e[39m"
	@$(CC) $(CFLAGS) -D N -D FT -o test_ft_vector_insert_n tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_insert_n"\e[39m"
	@$(CC) $(CFLAGS) -D N -o test_std_vector_insert_n tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◜"\t"test_ft_vector_insert_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_insert_it tests/vector_insert.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_insert_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_insert_it tests/vector_insert.cpp

vector_erase:  tests/vector_erase.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_erase"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_erase tests/vector_erase.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_erase"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_erase tests/vector_erase.cpp
	@printf "\e[36m\033[2K\r\t"◜"\t"test_ft_vector_erase_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_erase_it tests/vector_erase.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_erase_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_erase_it tests/vector_erase.cpp

vector_resize_reserve:  tests/vector_resize_reserve.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_resize"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_resize tests/vector_resize_reserve.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_resize"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_resize tests/vector_resize_reserve.cpp
	@printf "\e[36m\033[2K\r\t"◜"\t"test_ft_vector_reserve"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D SIZE -o test_ft_vector_reserve tests/vector_resize_reserve.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_reserve"\e[39m"
	@$(CC) $(CFLAGS) -D SIZE -o test_std_vector_reserve tests/vector_resize_reserve.cpp

vector_egal: tests/vector_egal.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_egal"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_egal tests/vector_egal.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_egal"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_egal tests/vector_egal.cpp

vector_construct: tests/vector_construct.cpp
	@printf "\e[36m\033[2K\r\t"◜"\t"test_ft_vector_construct"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_construct tests/vector_construct.cpp
	@printf "\e[36m\033[2K\r\t"◝"\t"test_std_vector_construct"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_construct tests/vector_construct.cpp
	@printf "\e[36m\033[2K\r\t"◞"\t"test_ft_vector_construct_range"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D RANGE -o test_ft_vector_construct_range tests/vector_construct.cpp
	@printf "\e[36m\033[2K\r\t"◟"\t"test_std_vector_construct_range"\e[39m"
	@$(CC) $(CFLAGS) -D RANGE -o test_std_vector_construct_range tests/vector_construct.cpp

# ◜
# ◝
# ◞
# ◟

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
	@rm -f test_ft_vector_resize
	@rm -f test_std_vector_resize
	@rm -f test_ft_vector_reserve
	@rm -f test_std_vector_reserve
	@rm -f test_ft_vector_egal
	@rm -f test_std_vector_egal
	@rm -f test_ft_vector_construct
	@rm -f test_std_vector_construct
	@rm -f test_ft_vector_construct_range
	@rm -f test_std_vector_construct_range
#	@printf "\t\e[31mCLEAN\t\t[ ✓ ]\n\e[39m"

re: clean all

.PHONY: all clean re benchmark vector compiling compiling_end