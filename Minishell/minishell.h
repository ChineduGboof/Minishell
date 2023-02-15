/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:12 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/15 13:44:46 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

# define SYNTAX_ERR_C	"\e[0;31m minishell:🔗 syntax error near unexpected token `%c'\n\e[0m"
# define SYNTAX_ERR_S	"\e[0;31m minishell:🔗 syntax error near unexpected token `%s'\n\e[0m"

typedef struct s_list
{
	char	**env;		//stores a copy of the environment
	// char	**file_ext;	//contains the file extensions /usr/local/bin
	// char	*verified_path;
	// char	**commands;		// contains each command 
	// char	**split_args;	//contains the args gotten by readline(), split by pipes
}	t_list;

int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(int c);
int		no_errors(char *str);
int		count_quotes(char *str, char quote);
int 	wrong_redirection(char *str, char rd);
int 	split_string(char *str, char ***words);

size_t	ft_strlen(const char *s);

char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*handle_quotes(char *str);
char 	*add_space(const char *str);
char	*lexer(char *str, t_list *data);
char	**dup_env(char **envp);
char	*expand_env(char *str, t_list *data);

void	ft_bzero(void *s, size_t n);
void	exec_fork(t_list *args);
void	ignore_str_in_quotes(char *str, int j, int i[]);
void 	remove_spaces(char *str);

#endif