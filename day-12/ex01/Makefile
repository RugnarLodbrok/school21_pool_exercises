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

NAME = ft_cat
FLAGS = -Wall -Wextra -Werror
HEADER = ./
SRC = ./*.c
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
