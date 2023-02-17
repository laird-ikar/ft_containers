# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:33:27 by bguyot            #+#    #+#              #
#    Updated: 2023/02/17 16:29:31 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: benchmark clean

benchmark: vector map

start_compiling:
	@printf "\e[34;1mCreating tests...\e[39;0m"

compiling_end:
	@printf "\e[96m\033[2K\r\t"\>"\t"Tests\ successfully\ compiled\ !"\n\e[39m"

vector: vector_start start_compiling vector_benchmark

vector_start:
	@printf "\e[37;1m\n\t#####################  Vector benchmark  #####################\t\n\n\e[39;0m"

vector_benchmark: tests_vector compiling_end
	@./benchmark.sh vector

map: map_start start_compiling map_benchmark

map_start:
	@printf "\e[37;1m\n\t######################   Map benchmark   ######################\t\n\n\e[39;0m"

map_benchmark: tests_map compiling_end
	@./benchmark.sh map

tests_vector: vector_assign vector_insert vector_erase vector_resize_reserve vector_egal vector_construct

tests_map: vector_assign #to change in the future

vector_assign:  tests/vector_assign.cpp
	@printf "\e[96m\n\t"◜"\t"test_ft_vector_assign"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_assign tests/vector_assign.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_assign"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_assign tests/vector_assign.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_assign_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_assign_it tests/vector_assign.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_assign_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_assign_it tests/vector_assign.cpp

vector_insert:  tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"◜"\t"test_ft_vector_insert"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_insert tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_insert"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_insert tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_insert_n"\e[39m"
	@$(CC) $(CFLAGS) -D N -D FT -o test_ft_vector_insert_n tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_insert_n"\e[39m"
	@$(CC) $(CFLAGS) -D N -o test_std_vector_insert_n tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"◜"\t"test_ft_vector_insert_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_insert_it tests/vector_insert.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_insert_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_insert_it tests/vector_insert.cpp

vector_erase:  tests/vector_erase.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_erase"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D VAL -o test_ft_vector_erase tests/vector_erase.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_erase"\e[39m"
	@$(CC) $(CFLAGS) -D VAL -o test_std_vector_erase tests/vector_erase.cpp
	@printf "\e[96m\033[2K\r\t"◜"\t"test_ft_vector_erase_it"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_erase_it tests/vector_erase.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_erase_it"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_erase_it tests/vector_erase.cpp

vector_resize_reserve:  tests/vector_resize_reserve.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_resize"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_resize tests/vector_resize_reserve.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_resize"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_resize tests/vector_resize_reserve.cpp
	@printf "\e[96m\033[2K\r\t"◜"\t"test_ft_vector_reserve"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D SIZE -o test_ft_vector_reserve tests/vector_resize_reserve.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_reserve"\e[39m"
	@$(CC) $(CFLAGS) -D SIZE -o test_std_vector_reserve tests/vector_resize_reserve.cpp

vector_egal: tests/vector_egal.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_egal"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_egal tests/vector_egal.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_egal"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_egal tests/vector_egal.cpp

vector_construct: tests/vector_construct.cpp
	@printf "\e[96m\033[2K\r\t"◜"\t"test_ft_vector_construct"\e[39m"
	@$(CC) $(CFLAGS) -D FT -o test_ft_vector_construct tests/vector_construct.cpp
	@printf "\e[96m\033[2K\r\t"\ ◝"\t"test_std_vector_construct"\e[39m"
	@$(CC) $(CFLAGS) -o test_std_vector_construct tests/vector_construct.cpp
	@printf "\e[96m\033[2K\r\t"\ ◞"\t"test_ft_vector_construct_range"\e[39m"
	@$(CC) $(CFLAGS) -D FT -D RANGE -o test_ft_vector_construct_range tests/vector_construct.cpp
	@printf "\e[96m\033[2K\r\t"◟"\t"test_std_vector_construct_range"\e[39m"
	@$(CC) $(CFLAGS) -D RANGE -o test_std_vector_construct_range tests/vector_construct.cpp

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

re: clean all

.PHONY: all clean re benchmark vector map start_compilingcompiling_end vector_start map_start