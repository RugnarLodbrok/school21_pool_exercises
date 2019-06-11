#!/bin/bash
rm libft.a
gcc -Wall -Wextra -Werror -c ft*.c
ar rc libft.a ft*.o
ranlib libft.a
rm *.o
