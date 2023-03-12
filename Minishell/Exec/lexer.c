/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:00 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 13:58:22 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*split_input_by_pipes(t_data *data, char ***commands)
{
	s_data->n_pipes = count_pipes(s_data->args, s_data->n_pipes);
	data = ft_calloc(sizeof(t_data), (s_data->n_pipes + 1));
	*commands = my_ft_split(s_data->args, '|');
	return (data);
}

static void	init_check_cmd(t_quote *for_all, int *i)
{
	for_all->dquote = 0;
	s_data->n_pipes = 1;
	*i = -1;
}

static int	valid_heredoc_op(t_data *data, int cmd_num)
{
	int	j;

	j = 0;
	if (s_data->heredoc_count > 1)
		return (0);
	while (data[cmd_num].op[j])
	{
		if (my_strncmp(data[cmd_num].op[j], "<<", 2) && cmd_num > 0)
			return (0);
		if (my_strncmp(data[cmd_num].op[j], "<<", 2))
		{
			s_data->heredoc_count++;
			return (1);
		}
		j++;
	}
	return (1);
}

t_data	*validate(t_data *data)
{
	t_quote	for_all;
	char		**commands;
	int			i;

	init_check_cmd(&for_all, &i);
	uneven_quotes(s_data->args, &for_all);
	if (!check_input_errors(s_data->n_pipes, s_data->args, &for_all))
		return (0);
	data = split_input_by_pipes(data, &commands);
	while (++i < s_data->n_pipes)
	{
		if (!init_data(&data[i], &for_all, commands[i], s_data->envp)
			|| !process_cmds(&data[i], &for_all) || \
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
