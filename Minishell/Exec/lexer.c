/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:00 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 16:45:40 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*split_input_by_pipes(t_data *data, char ***commands)
{
	g_args->n_pipes = count_pipes(g_args->args, g_args->n_pipes);
	data = ft_calloc(sizeof(t_data), (g_args->n_pipes + 1));
	*commands = my_ft_split(g_args->args, '|');
	return (data);
}

static void	init_check_cmd(int *i)
{
	g_args->dquote = false;
	g_args->n_pipes = 1;
	*i = -1;
}

static int	valid_heredoc_op(t_data *data, int cmd_num)
{
	int	j;

	j = 0;
	if (g_args->heredoc_count > 1)
		return (0);
	while (data[cmd_num].op[j])
	{
		if (my_strncmp(data[cmd_num].op[j], "<<", 2) && cmd_num > 0)
			return (0);
		if (my_strncmp(data[cmd_num].op[j], "<<", 2))
		{
			g_args->heredoc_count++;
			return (1);
		}
		j++;
	}
	return (1);
}

t_data	*validate(t_data *data)
{
	char	**commands;
	int		i;

	init_check_cmd(&i);
	uneven_quotes(g_args->args);
	if (!check_input_errors(g_args->n_pipes, g_args->args))
		return (0);
	data = split_input_by_pipes(data, &commands);
	while (++i < g_args->n_pipes)
	{
		if (!init_data(&data[i], commands[i], g_args->envp)
			|| !process_cmds(&data[i]) || \
			!valid_heredoc_op(data, i))
		{
			free_2d_array(commands);
			free_t_data_members(data);
			free(data);
			data = NULL;
			return (0);
		}
	}
	free_2d_array(commands);
	execute(data);
	return (data);
}
