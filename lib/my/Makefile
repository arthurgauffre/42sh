##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## task01
##

SRC		=	function/my_revstr.c	\
			function/my_str_isprintable.c	\
			function/my_str_isupper.c	\
			function/my_compute_power_rec.c	\
			function/my_strlen.c	\
			function/my_compute_square_root.c	\
			function/my_strlowcase.c	\
			function/my_strcapitalize.c	\
			function/my_strncat.c	\
			function/my_strcat.c	\
			function/my_strncmp.c	\
			function/my_isneg.c	\
			function/my_strcmp.c	\
			function/my_strncpy.c	\
			function/my_is_prime.c	\
			function/my_strcpy.c	\
			function/my_putchar.c	\
			function/my_puterror.c	\
			function/my_str_isalpha.c	\
			function/my_put_nbr.c	\
			function/my_str_islower.c	\
			function/my_strdup.c	\
			function/my_strupcase.c	\
			function/my_putstr.c	\
			function/my_str_isnum.c	\
			my_str_to_word_array/my_str_to_word_array.c	\
			my_str_to_word_array/parcour_word.c	\
			my_str_to_word_array/get_word.c	\
			my_str_to_word_array/len_word.c

TEST		=	test_my_compute_power_rec.c		\
				test_my_compute_square_root.c	\
				test_my_is_prime.c				\
				test_my_isneg.c				\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	=	-I../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
