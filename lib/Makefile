##
## EPITECH PROJECT, 2023
## printf
## File description:
## Makefile
##

NAME := ../libmy.a

SRC := my_printf.c\
	   my_printf2.c\
	   print_arg.c\
	   my_strlen.c\
	   printf_other.c\
	   my_strcmp.c

OBJ := $(SRC:.c=.o)


$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean :
	find . -type f -name '*~' -delete
	find . -type f -name '#*#' -delete
	find . -type f -name '*.o' -delete

fclean : clean
	rm  -f $(NAME)
	rm -f a.out

re : fclean all

.PHONY : all re fclean clean
