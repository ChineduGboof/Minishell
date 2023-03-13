# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:16:15 by gboof             #+#    #+#              #
#    Updated: 2023/03/13 16:52:55 by cegbulef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# ifndef CEGBULEF
# .SILENT:
# endif


NAME = minishell

FILES = main.c\
		\
		./Exec/hereDoc.c\
		./Exec/exec_pipes.c\
		./Exec/executor.c\
		./Exec/get_path.c\
		./Exec/lexer.c\
		./Exec/fork_child.c\
		./Exec/redirection.c\
		./Exec/signal_handler.c\
		./Exec/open_rd_files.c\
		\
		./Parse/parser.c\
		./Parse/handle_expansions.c \
		./Parse/ft_split.c \
		./Parse/my_ft_split.c \
		./Parse/parse_commands.c \
		./Parse/redirections.c \
		./Parse/sort_redirections.c \
		./Parse/handle_rd.c \
		./Parse/rd_utils.c \
		./Parse/expand_utils.c \
		./Parse/utils1.c \
		./Parse/utils2.c \
		./Parse/utils3.c \
		./Parse/utils4.c \
		./Parse/utils5.c \
		\
		./Builtin/exit.c\
		./Builtin/ft_cd.c\
		./Builtin/ft_pwd.c\
		./Builtin/ft_echo.c\
		./Builtin/builtin.c\
		\
		./Env/shlvl.c\
		./Env/ft_env.c\
		./Env/ft_unset.c\
		./Env/ft_export.c\
		./Env/env_utils.c\
		./Env/env_utils_2.c\
		./Env/export_utils.c\
		./Env/export_utils_2.c\
		\
		./Free/free_cmds.c\
		./Free/free_structs.c\

HEADERS = ./minishell.h\
		./libft/libft.h\

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror -lreadline -L /usr/local/Cellar/readline/8.1/lib -I /usr/local/Cellar/readline/8.1/include

sanitize = -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

LIBFT = ./libft/libft.a

CC = gcc

all: $(NAME) $(HEADER) $(FILES)

$(NAME): $(OBJ)
	@make -C ./libft


	$(CC) -g $(FLAGS) $(FILES) $(LIBFT) -lreadline -o minishell

	
	@echo "													 Made by : \033[1;91mCegbulef\033[m"
	@echo "      ___                       ___                       ___           ___           ___                                  "
	@echo "     /__/\        ___          /__/\        ___          /  /\         /__/\         /  /\                                 "
	@echo "    |  |::\      /  /\         \  \:\      /  /\        /  /:/_        \  \:\       /  /:/_                                "
	@echo "    |  |:|:\    /  /:/          \  \:\    /  /:/       /  /:/ /\        \__\:\     /  /:/ /\    ___     ___   ___     ___  "
	@echo "  __|__|:|\:\  /__/::\      _____\__\:\  /__/::\      /  /:/ /::\   ___ /  /::\   /  /:/ /:/_  /__/\   /  /\ /__/\   /  /\ "
	@echo " /__/::::| \:\ \__\/\:\__  /__/::::::::\ \__\/\:\__  /__/:/ /:/\:\ /__/\  /:/\:\ /__/:/ /:/ /\ \  \:\ /  /:/ \  \:\ /  /:/ "
	@echo " \  \:\~~\__\/    \  \:\/\ \  \:\~~\~~\/    \  \:\/\ \  \:\/:/~/:/ \  \:\/:/__\/ \  \:\/:/ /:/  \  \:\  /:/   \  \:\  /:/  "
	@echo "  \  \:\           \__\::/  \  \:\  ~~~      \__\::/  \  \::/ /:/   \  \::/       \  \::/ /:/    \  \:\/:/     \  \:\/:/   "
	@echo "   \  \:\          /__/:/    \  \:\          /__/:/    \__\/ /:/     \  \:\        \  \:\/:/      \  \::/       \  \::/    "
	@echo "    \  \:\         \__\/      \  \:\         \__\/       /__/:/       \  \:\        \  \::/        \__\/         \__\/     "
	@echo "     \__\/                     \__\/                     \__\/         \__\/         \__\/                                 "
	@echo "						Compilation of $(NAME):  \033[1;32mOK\033[m"


leaks_fd:
	make re && make clean && valgrind --track-fds=yes  ./minishell
	
leaks:
	make re && make clean \
	&& valgrind --leak-check=full \
	--track-origins=yes \
	--show-leak-kinds=all -s \
	./minishell

norm:
	norminette ./* ./libft/*

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf minishell
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
