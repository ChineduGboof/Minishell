# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 19:32:43 by cegbulef          #+#    #+#              #
#    Updated: 2023/02/15 12:49:47 by cegbulef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address


RFLAGS = -L /usr/local/opt/readline/lib -l readline

RM = rm -rf

SRCS = 	main.c utils.c error.c tokens.c ft_split.c whitespace.c split2.c expand.c
# exec.c ft_split_quotes.c

$(NAME) :
	gcc $(CFLAGS) $(RFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re