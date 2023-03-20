/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:16 by gboof             #+#    #+#             */
/*   Updated: 2023/03/18 21:43:30 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	absolute_path(t_data *data, int cmd_num)
{
	if (data[cmd_num].s_cmd && data[cmd_num].s_cmd[0])
	{
		if (!access(data[cmd_num].s_cmd[0], F_OK))
		{
			if (execve(data[cmd_num].s_cmd[0],
					data[cmd_num].s_cmd, g_args->envp->env) < 0)
			{
				ft_putstr_fd("\033[1;31m [minishell]: \033[0m ", 2);
				perror(data[cmd_num].s_cmd[0]);
				close_fd(data);
				free_t_data_members(data);
				free(data);
				exit(EXIT_FAILURE);
			}
			return (1);
		}
	}
	return (0);
}

static void	slash_command(t_data *data, int cmd_num)
{
	if (data[cmd_num].s_cmd && data[cmd_num].s_cmd[0] && ft_strncmp
		(data[cmd_num].s_cmd[0], "./", 2) == 0)
	{
		if (execve(data[cmd_num].s_cmd[0],
				data[cmd_num].s_cmd, g_args->envp->env) < 0)
		{
			ft_putstr_fd("\033[1;31m [minishell]: \033[0m ", 2);
			perror(data[cmd_num].s_cmd[0]);
		}
		close_fd(data);
		free_t_data_members(data);
		free(data);
		exit(127);
	}
}

static void	ft_child_exec(t_data *data, int cmd_num)
{
	char	*envir_value;

	absolute_path(data, cmd_num);
	envir_value = get_env_value(g_args->envp, "PATH");
	slash_command(data, cmd_num);
	if (data[cmd_num].s_cmd && data[cmd_num].s_cmd[0])
	{
		data[cmd_num].path = get_path(envir_value, &data[cmd_num], \
					g_args->args);
		if (data[cmd_num].path)
		{
			if (execve(data[cmd_num].path, data[cmd_num].s_cmd, \
					g_args->envp->env) < 0)
			{
				ft_putstr_fd("\033[1;31m [minishell]: \033[0m ", 2);
				ft_putstr_fd(data->s_cmd[0], 2);
				ft_putstr_fd(": command not found\033[0m\n", 2);
			}
		}
	}
	free(envir_value);
	close_fd(data);
	free_t_data_members(data);
	g_args->return_state = 127;
	exit(127);
}

static int	is_heredoc(t_data *data)
{
	if (!data->op[0])
		return (0);
	if (ft_strcmp(data->op[0], "<<") == 0)
		return (1);
	return (0);
}

void	fork_child(t_data *data, int cmd_num)
{
	pid_t	child_pid;

	if ((data[cmd_num].s_cmd && data[cmd_num].s_cmd[0] && \
			data[cmd_num].s_cmd[0][0]) || is_heredoc(data))
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("\033[1;31m [minishell] \033[0m");
			exit(-1);
		}
		else if (child_pid == 0)
		{
			exec_pipeline_cmd(data, cmd_num);
			check_redirection(data, cmd_num);
			close_fd(data);
			ft_child_exec(data, cmd_num);
		}
	}
}
