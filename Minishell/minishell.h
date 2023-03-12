/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:39 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 17:39:28 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define SYNTAX_ERR_C	"\e[0;31m Minishell:🔗 syntax error near unexpected token `%c'\n\e[0m"
# define SYNTAX_ERR_S	"\e[0;31m Minishell:🔗 No such file or directory ⚙️ `%s'\n\e[0m"

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define END "\033[0m"

typedef struct s_envp
{
	char			**env;
	size_t			shlvl;
}			t_envp;

typedef struct s_quote
{
	int		dquote;
	char	*parsed_cmd;
	int		pipes_nb;
}		t_quote;

typedef struct s_data
{
	char		**op;
	char		**fname;
	char		**s_cmd;
	char		*path;
	int			fd[2];
	int			fd_temp;
	int			fd_rd;
	int			status;
	char		**env;
	char		*cmd;
	char		*cmd_args;
	char		**rd;
	int			flag;
	t_quote	all;
}			t_data;

typedef struct s_shell
{
	t_envp		*envp;
	int			return_state;
	int			n_pipes;
	char		*args;
	int			fd_temp;
	int			heredoc_count;
}		t_shell;

t_shell	*s_data;

/*---------------------------------- parser.c --------------------------------*/
int		copy_only_cmd(t_data *data);
void	copy_cmd_to_array(t_data *data);
void	copy_rd_n_fname(t_data *data, int x);
void	alloc_rd_n_fname(t_data *data, int x);
int		sort_rd_n_fname(t_data *data);
int		copy_all_rd_args(t_data *data);
int		count_rd(t_data *data);
char	*check_dquote(char *cmd, t_quote *data, t_data *info);
int		copy_rd_arg(t_data *data, int i, int x);
int		get_rd_fname_size(t_data *data, int i);
int		ft_isspace(char c);
int		scan_rd(t_data *data);
int		ft_strlen_n(const char *s);
int		count_words(char const *s, char c);
char	*ft_getenv(char *name, char **env);
char	**my_ft_split(char const *s, char c);
char	*checkpath(char *str, char **env);
char	*check_expand(char *cmd, t_data *data);
char	*replace_sub_str_to_expand(char *cmd, int start, int len, char **env);
int		ft_strncomp(const char *s1, const char *s2, int n);
int		ft_exec(t_data *data);
int		init_data(t_data *data, t_quote *for_all, char *cmd, t_envp *envp);
void	print_error(char *s);
int		no_spaces(char *cmd);
t_data	*validate(t_data *data);
char	*remove_dollar(char *cmd, int start);
void	escape_rd(t_data *data, int *i);
void	alloc_rd(t_data *data, int nb_of_op);
int		find_rd_pos(t_data *data, int i);
int		pos_of_closing_quotes(int x, t_data *data);
int		no_rd_fname2(t_data *data, int i);
int		no_rd_fname(t_data *data, int i);
int		get_rd_fname_size(t_data *data, int i);
int		esc_rd_args(t_data *data, int *i, int j);
int		adjust_i(t_data *data, int i);
int		adjust_j(t_data *data, int i, int j);
int		offset_j(t_data *data, int i, int j, char c);
int		skip_quote_i(t_data *data, int i);
int		skip_quote_j(t_data *data, int i, int j);
int		ft_strlen_n(const char *s);
int		isenv_se(char c);
int		isenv(char c);
char	*check_expand_helper_2(char *final_expanded, int *i, t_data *data);
char	*ft_strndup(char *cmd, int length, int i);
char	*check_expand_1(int i, char *final_expanded, char **env);
char	*check_expand_helper_0(char *final_expanded, int *i, t_data *data);
int		check_expand_helper_01(char *final_expanded, int *i, t_data *data);
int		check_expand_helper_1(char *final_expanded, int *i);
int		check_flag(t_data *info, int i, char c);
int		increment_till_next_quote(t_quote *data, char *cmd, int i, char c);
int		find_rd(t_data *data, int i);
void	print_error(char *s);
int		init_data(t_data *data, t_quote *for_all, char
			*cmd_holder, t_envp *envp);
char	*copy_parsed_cmd(char *cmd, char *new);
char	*allocate_parsed_cmd(char *cmd);
int		uneven_quotes(char *cmd, t_quote *data);
int		rd_fname_size(t_data *data, int i, int j);
int		esc_rd(t_data *data, int i);
char	*check_expand_helper_final(char *final_expanded, int *i, t_data *data);
int		check_input_errors(int pipe_num, char *cmd_line, t_quote *for_all);
int		scan_rd(t_data *data);
int		skip_quoted_string(const char *s, int i);
int		count_pipes(char *cmd_line, int j);
int		process_cmds(t_data *data, t_quote *for_all);
char	*no_expand_found(char **cmd, int start, int length);
char	*edit_expanded(char *expanded, char *cmd, int length, int start);

/*---------------------------------  Signals ---------------------------------*/
void	trap_signals(void);

/*--------------------------  Built_in_commands ------------------------------*/
int		ft_echo(t_data *data, int cmd_num);
int		ft_cd(t_data *data, t_envp *envp, int cmd_num);
int		ft_pwd(t_data *data, int cmd_num);
int		ft_exit(t_data *data, int cmd_num);
int		ft_unset(t_data *data, t_envp *envp, int cmd_num);
int		ft_env(t_data *data, t_envp *envp, int cmd_num);
int		ft_export(t_data *data, t_envp *envp, int cmd_num);

/*--------------------------  Built_in commands handlers ---------------------*/
int		builtin(t_data *data, int cmd_num);
int		builtin_checker(t_data *data, int cmd_num);
int		piped_built_in(t_data *data, int cmd_num);

/*----------------------------# Environment_utils #---------------------------*/
int		sizeof_2d_array(char **array);
void	add_to_env(t_envp *envp, char *to_add);
void	del_from_env(t_envp *envp, char *to_delete);
char	**dup_2darray(char **array);
size_t	get_env_name_len(char **env, int index);
void	shlvl_edge_cases(t_envp *envp);
void	add_to_shlvl(void);
int		env_var_exists(t_envp *envp, char *to_compare);

/*-----------------------------# Cleaning_utils #-----------------------------*/
void	free_struct_s_cmd(t_data *data, int cmd_num);
void	free_struct_fname(t_data *data, int cmd_num);
void	free_struct_op(t_data *data, int cmd_num);
void	close_fd(t_data *data);
void	free_t_data_members(t_data *data);
void	free_readline(void);

/*-----------------------------# Export_utils #-------------------------------*/
int		export_error(char *err_cmd);
int		already_exist(char *to_add, t_envp *envp);
int		valid_toadd(t_data *data, int index);
void	add_to_env_value(t_envp *envp, char *new_cmd);
char	*get_env_value(t_envp *envp, char *element_name);
void	export_print(t_envp *envp);
char	*delchar(char *cmd);
void	export_print_2(t_envp *envp, int *i, int *j);
void	sorting_environment(t_envp *envp);

/*--------------------------# redirection_utils #-----------------------------*/
int		check_redirection(t_data *data, int cmd_num);
void	check_rp_redirection(t_data *data, int cmd_num, int i);
void	check_ap_redirection(t_data *data, int cmd_num, int i);
int		ft_open_rp(char *str);
int		ft_open_ap(char *str);
int		ft_open(char *str);
int		ft_here_doc_2(char *str);
int		my_strncmp(const char *s1, const char *s2, int n);
int		heredoc_exec(t_data *data, char *str, int cmd_num);

/*--------------------------------- execution --------------------------------*/
int		execute(t_data *data);
void	exec_pipeline_cmd(t_data *data, int cmd_num);
void	free_2d_array(char **array);
void	free_env(t_envp *envp);
void	fork_child(t_data *data, int cmd_num);
char	*get_path(char *path, t_data *data, char *args);
void	fd_temp_closer(void);
void	fd_rd_closer(t_data *data, int cmd_num);
void	wait_children(void);

/*----------------------------------------------------------------------------*/
#endif
