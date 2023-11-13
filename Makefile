##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## setting_up
##

NAME = setting_up

SRC = setting_up.c\
	  solver.c\
	  util.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all: $(NAME)

clean:
		find . -type f -name '*~' -delete
		find . -type f -name '#*#' -delete
		find . -type f -name '*.o' -delete

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

$(NAME) : $(OBJ)
		make -C lib/
		gcc -o $(NAME) $(OBJ) -L./ -lmy

.PHONY : all re fclean clean
