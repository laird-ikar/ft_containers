# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:58:54 by bguyot            #+#    #+#              #
#    Updated: 2023/02/08 16:34:30 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

FILES			=	\
					tester

SRC_DIR			=	src/tester/
SRC_FIL			=	$(FILES)
SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))

OBJS			=	$(SRCS:.cpp=.o)

CC				=	c++
CANDCPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror -fsanitize=address -g

$(NAME): ft_tester std_tester

all: $(NAME)
	@printf "\t\e[96mALL\t\t[ ✓ ]\n\e[39m"

ft_tester: $(OBJS)
	@$(CC) $(CANDCPPFLAGS) -o ft_tester $(OBJS)

std_tester: $(OBJS)
	@$(CC) $(CANDCPPFLAGS) -o std_tester $(OBJS)

%.o: %.cpp %.hpp %.tpp
	@printf "\e[36m\033[2K\r\t\t"$@"\e[39m"
	@$(CC) $(CANDCPPFLAGS) -c -o $@ $<
	@printf "\e[36m\033[F\033[2K\r\tCOMPILATION\t[ ✓ ]\n\e[39m"

clean:
	@printf "\t\e[31mCLEAN\t\t[ ✓ ]\n\e[39m"
	@rm -f $(OBJS)

fclean: clean
	@printf "\t\e[35mFCLEAN\t\t[ ✓ ]\n\e[39m"

re: fclean all
	@printf "\t\e[96mRE\t\t[ ✓ ]\n\e[39m"

.PHONY: all clean fclean re