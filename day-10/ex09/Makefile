# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 17:21:02 by ksticks           #+#    #+#              #
#    Updated: 2019/06/17 17:21:03 by ksticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
FLAGS = -Wall -Wextra -Werror
HEADER = ./headers/
SRC = ./src/*.c
OPTION = -I $(HEADER)
OBJ = *.o

ALL : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(FLAGS) $(OPTION) $(SRC)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean ALL
