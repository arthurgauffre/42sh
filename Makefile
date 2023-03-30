##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil antman binary
##

SRC		=	shell.c				\
			my_tablen.c			\
			free_tab.c			\
			my_str_cut.c		\
			env.c				\
			echo.c				\
			mysh.c				\
			prompt.c			\
			read_terminal.c		\
			command.c			\
			builtins.c			\
			cd_builtin.c		\
			binary.c			\
			pwd.c				\
			setenv.c			\
			unsetenv.c			\
			my_str_isalphanum.c	\
			null_command.c		\
			replace_tab_with_space.c	\
			all_space_or_tab.c			\
			main.c

DIR_SRC 	= 	$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/ -I lib/include/

NAME		=	mysh

MY_LIB		=	-L lib/my -lmy

all: 	make_lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(MY_LIB)

make_lib:
	make -C lib/my

clean:
	make -C lib/my clean
	rm -f $(OBJ) vgcore* *.gc*

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re make_lib
