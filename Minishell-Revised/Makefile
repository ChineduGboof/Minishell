# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 19:32:43 by cegbulef          #+#    #+#              #
#    Updated: 2023/02/23 14:30:29 by cegbulef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address


RFLAGS = -L /usr/local/opt/readline/lib -l readline

RM = rm -rf

SRCS = 	main.c utils.c error.c lexer.c my_ft_split.c free.c init.c \
		runtime.c runtime2.c expand.c

$(NAME) :
	gcc $(CFLAGS) $(RFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re