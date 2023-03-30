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

SRC_TEST	=	src/env.c				\
				src/shell.c				\
				src/my_tablen.c			\
				src/free_tab.c			\
				src/my_str_cut.c		\
				src/echo.c				\
				src/mysh.c				\
				src/prompt.c			\
				src/read_terminal.c		\
				src/command.c			\
				src/builtins.c			\
				src/cd_builtin.c		\
				src/binary.c			\
				src/pwd.c				\
				src/setenv.c			\
				src/unsetenv.c			\
				src/replace_tab_with_space.c	\
				src/my_str_isalphanum.c


DIR_SRC 	= 	$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/ -I lib/include/ -ggdb3

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

tests_run: make_lib
	gcc -o unit_tests $(SRC_TEST) tests/test_minishell.c \
	--coverage -lcriterion $(CPPFLAGS) $(MY_LIB)
	./unit_tests

.PHONY: all clean fclean re make_lib tests_run
