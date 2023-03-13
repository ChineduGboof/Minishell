/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:24 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 16:51:52 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_pipes(char *cmd_line, int j)
{
	int		i;
	char	c;

	i = 0;
	while (cmd_line[i])
	{
		if ((cmd_line[i] == 39 || cmd_line[i] == 34))
		{
			c = cmd_line[i];
			i++;
			while (cmd_line[i] != c && cmd_line[i])
				i++;
		}
		if ((cmd_line[i] == '|' && cmd_line[i + 1] == '|')
			|| (cmd_line[i] == '|' && cmd_line[i + 1] == 0))
		{
			print_error("bash: syntax error near unexpected token `|'");
			return (100);
		}
		if (cmd_line[i] == '|')
			j++;
		i++;
	}
	return (j);
}

int	handle_rd_args(t_data *data)
{
	int	x;
	int	flag;

	x = 0;
	flag = scan_rd(data);
	if (flag == 0)
	{
		data->rd = NULL;
		data->op = NULL;
		data->fname = NULL;
		return (0);
	}
	copy_all_rd_args(data);
	sort_rd_n_fname(data);
	while (data->rd[x])
	{
		free(data->rd[x]);
		x++;
	}
	free(data->rd);
	return (1);
}

int	process_cmd_args(t_data *data)
{
	int	x;
	int	y;

	if (!handle_rd_args(data))
		return (0);
	x = 0;
	if (copy_only_cmd(data))
	{
		x = 0;
		y = count_words(data->cmd, ' ');
		free(data->cmd);
		while (x < y)
		{
			data->s_cmd[x] = check_expand(data->s_cmd[x], data);
			data->s_cmd[x] = check_dquote
				(data->s_cmd[x], data);
			x++;
		}
	}
	return (1);
}

int	process_cmds(t_data *data)
{
	if (data->cmd_args)
	{
		if (!process_cmd_args(data))
			return (0);
	}
	else
	{
		print_error("bash: syntax error near unexpected token `|'");
		return (0);
	}
	return (1);
}

char	*remove_dollar(char *cmd, int start)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(ft_strlen_n(cmd));
	while ((cmd[i]) && i < start)
	{
		new[i] = cmd[i];
		i++;
	}
	i++;
	while (cmd[i])
	{
		new[i - 1] = cmd[i];
		i++;
	}
	new[i - 1] = 0;
	free(cmd);
	return (new);
}
