/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:12 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/01 20:51:03 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <time.h>
# include <readline/readline.h>
# include <readline/history.h>

# define SYNTAX_ERR_C	"\e[0;31m minishell:🔗 syntax error near unexpected token `%c'\n\e[0m"
# define SYNTAX_ERR_S	"\e[0;31m minishell:🔗 No such file or directory ⚙️ `%s'\n\e[0m"

typedef struct s_envp
{
	char	**env;
	// size_t			shlvl;
}			t_envp;

typedef struct s_quote
{
	char	*parsed_cmd;
	int		pipes_nb;
}	t_quote;

typedef struct s_data
{
	char		**op;	// operator
	char		**fname;	// filename
	char		**s_cmd;	// s_cmd
	char		*path;		// path
	// int			fd[2];
	// int			fd_temp;
	// int			fd_rd;
	// int			status;
	char		**env;
	char		*cmd;
	char		*cmd_args;	// full command
	char		**rd;	// full_op
	bool		flag;
	// t_quote		all;
}			t_data;

typedef struct s_shell
{
	char	*args;
	int		n_pipes;
	bool	dquote;
	int		i;
	int		return_state;
	int		fd_temp;
	t_envp	*envp;
	// char	*parsed_cmd;
	// char	**env;
	// int		wc;
}	t_shell;

t_shell *s_data;

// int		ft_isalnum(int c);
// int		ft_isdigit(int c);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(char c);
int		no_rd_fname(t_data *data, int i); //error_for_size_op
int		no_rd_fname2(t_data *data, int i);
int		errors(void);
int		no_spaces(char *str);
int		uneven_quotes(char *str);	//check_dquote_only
int		pipe_stats(char *str, int n_pipes);
int		init_data(t_data *data, char *commands, t_envp *envp);
int		pos_of_closing_quotes(int i, t_data *data);		//incrementer_3
int		count_rd(t_data *data);		//count_op
int		find_rd(t_data *data, int i);	//count_untill_next_op
int		rd_fname_size(t_data *data, int i, int j);
int		get_rd_fname_size(t_data *data, int rd);	//check_rd_size
int		esc_rd_args(t_data *data, int *i, int j);	//check_size_of_full_op
int		valid_rd(int x, t_data *data, int rd_num);
int		scan_rd(t_data *data);	//check_full_op
int		find_rd_pos(t_data *data, int i);	//incrementer55
int		copy_rd_arg(t_data *data, int i, int x);	//copy_op_line
int		copy_all_rd_args(t_data *data);	//copy_all_op
int		sort_rd_n_fname(t_data *data);
int		count_words(char const *s, char c);
int		esc_rd(t_data *data, int i);	//skip_op

int		copy_only_cmd(t_data *data);

size_t	ft_strlen(const char *str);

// char	*ft_strcpy(char *dest, char *src);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strstr(char *str, char *to_find);
// char	*ft_strdup(const char *s1);
char	**my_ft_split(char const *s, char c);	//ft_split_og
// char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *str, int fd);
void	disp_error(char *str);
void	free_2d_array(char **array);
void	free_readline(void);
void	free_tdata(t_data *data);
void	init_some_values(void);
void	error_msg(char *str);
void	escape_rd(t_data *data, int *i);	//skip_oop
void	alloc_rd(t_data *data, int rd_num);	//alloc_op
void	copy_rd_arg2(t_data *data, int i, int j, int x);
void	alloc_rd_n_fname(t_data *data, int x);	//allocate_op_and_file
void	copy_rd_n_fname(t_data *data, int x);	//copy_op_and_file

t_data	*alloc_data(t_data *data, char ***commands);
t_data	*validate(t_data *data);

int		skip_j(t_data *data, int i, int j, char c);
int		skip_i(t_data *data, int i);
int		incrementii(t_data *data, int i);
int		incrementjj(t_data *data, int i, int j);
int		increment_j(t_data *data, int i, int j);
int		increment_i(t_data *data, int i);
void	start_copy_cmd(t_data *data);
int		increment_till_next_quote( char *cmd, int i, char c);
char	*allocate_parsed_cmd(char *cmd);
char	*check_dquote(char *cmd, t_data *data);

#endif