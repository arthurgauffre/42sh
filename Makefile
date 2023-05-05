##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil antman binary
##

SRC		=	builtins/builtins.c		\
			builtins/cd_builtin.c	\
			builtins/env.c			\
			builtins/pwd.c			\
			builtins/unsetenv.c		\
			builtins/setenv.c		\
			exec/binary.c			\
			exec/command.c			\
			exec/null_command.c		\
			shell/echo.c			\
			shell/mysh.c			\
			shell/prompt.c			\
			shell/shell.c			\
			str/all_space_or_tab.c			\
			str/my_str_cut.c				\
			str/my_str_isalphanum.c			\
			str/read_terminal.c				\
			str/replace_tab_with_space.c	\
			tab/my_tablen.c			\
			tab/free_tab.c			\
			main.c \
			str/line_editing.c		\
			str/get_input.c

DIR_SRC 	= 	$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -ggdb3

CPPFLAGS	=	-I./include/ -I lib/include/

NAME		=	42sh

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
