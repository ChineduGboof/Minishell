/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:11:29 by gboof             #+#    #+#             */
/*   Updated: 2023/03/01 14:27:41 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	check_dquote_only
*/
int	uneven_quotes(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"'))
		{
			c = str[i];
			i++;
			while (str[i] != c)
			{
				if (str[i] == 0)
				{
					s_data->dquote = true;
					return (0);
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	pipe_stats(char *str, int n_pipes)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"'))
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
				i++;
		}
		if ((str[i] == '|' && str[i + 1] == '|')
			|| (str[i] == '|' && str[i + 1] == 0))
		{
			error_msg ("syntax error near unexpected token `|'");
			return (-1);
		}
		if (str[i] == '|')
			n_pipes++;
		i++;
	}
	return (n_pipes);
}

int	errors(void)
{
	
	if (s_data->dquote == true)
	{
		error_msg ("error: unclosed quotes");
		return (0);
	}
	if (pipe_stats(s_data->args, s_data->n_pipes) == -1)
		return (0);
	return (1);
}

/*
	error_for_op => no_rd_fname2
	it checks if there is a file name after the rd or another rd
	it throws an error if it finds another rd instead of a file name
*/
int	no_rd_fname2(t_data *data, int i)
{
	if (data->cmd_args[i] == '<' || data->cmd_args[i] == '>')
	{
		printf(SYNTAX_ERR_C, data->cmd_args[i]);
		s_data->return_state = 258;
		rl_on_new_line();
		return (1);
	}
	return (0);
}

/*
	error_for_size_op => no_rd_file_error
	it checks if there is a file name after the rd or another rd
	it throws an error if it finds another rd instead of a file name
	it also throws an error if the rd is the last argument
*/
int	no_rd_fname(t_data *data, int i)
{
	if (data->cmd_args[i] == '<' || data->cmd_args[i] == '>'
		|| data->cmd_args[i] == '\0')
	{
		printf(SYNTAX_ERR_C, data->cmd_args[i]);
		s_data->return_state = 258;
		rl_on_new_line();
		return (1);
	}
	return (0);
}

int	check_flag(t_data *data, int i, char c)
{
	if (c == 39)
		data->flag = 1;
	else
		data->flag = 0;
	i++;
	return (i);
}

char	*check_dquote(char *cmd, t_data *data)
{
	int		i;
	char	c;
	int		flag;
	char	*new;

	i = 0;
	flag = 0;
	while (cmd[i])
	{
		if ((cmd[i] == 39 || cmd[i] == 34))
		{
			flag = 1;
			c = cmd[i];
			i = check_flag(data, i, c);
			i = increment_till_next_quote(cmd, i, c);
		}
		i++;
	}
	if (s_data->dquote == 0 && flag == 1)
		new = allocate_parsed_cmd(cmd);
	else
		return (cmd);
	free(cmd);
	return (new);
}