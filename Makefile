# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:58:54 by bguyot            #+#    #+#              #
#    Updated: 2023/02/13 18:17:16 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

FILES			=	\
					tester

SRC_DIR			=	src/tester/
SRC_FIL			=	$(FILES)
SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))

OBJS			=	$(SRCS:.cpp=.o)

CC				=	@c++
CFLAGS			=	-std=c++98 -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)
	@printf "\t\e[96mALL\t\t[ ✓ ]\n\e[39m"

$(NAME): ft_tester std_tester

ft_tester:
	$(CC) $(CFLAGS) -D FT -o ft_tester src/tester/tester.cpp

std_tester:
	$(CC) $(CFLAGS) -o std_tester src/tester/tester.cpp

benchmark:
	make -C src/tester

clean:
	@printf "\t\e[31mCLEAN\t\t[ ✓ ]\n\e[39m"
	@rm -f $(OBJS)

fclean: clean
	@printf "\t\e[35mFCLEAN\t\t[ ✓ ]\n\e[39m"
	@rm -f ft_tester std_tester

re: fclean all
	@printf "\t\e[96mRE\t\t[ ✓ ]\n\e[39m"

.PHONY: all clean fclean re