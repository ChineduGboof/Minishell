/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:18:20 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 17:39:28 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_checker(t_data *data, int cmd_num)
{
	if (data[cmd_num].s_cmd && data[cmd_num].s_cmd[0])
	{
		if (ft_strcmp(data[cmd_num].s_cmd[0], "cd") == 0
			|| strcmp(data[cmd_num].s_cmd[0], "echo") == 0
			|| ft_strcmp(data[cmd_num].s_cmd[0], "pwd") == 0
			|| ft_strcmp(data[cmd_num].s_cmd[0], "env") == 0
			|| ft_strcmp(data[cmd_num].s_cmd[0], "unset") == 0
			|| ft_strcmp(data[cmd_num].s_cmd[0], "export") == 0
			|| ft_strcmp(data[cmd_num].s_cmd[0], "exit") == 0)
			return (1);
	}
	return (0);
}

static int	forked_builtin(t_data *data, int cmd_num)
{
	if (ft_cd(data, s_data->envp, cmd_num) \
	|| ft_echo(data, cmd_num) \
	|| ft_pwd(data, cmd_num) \
	|| ft_env(data, s_data->envp, cmd_num) \
	|| ft_unset(data, s_data->envp, cmd_num) \
	|| ft_export(data, s_data->envp, cmd_num))
	{
		close_fd(data);
		exit (EXIT_SUCCESS);
	}
	else if (ft_exit(data, cmd_num))
		exit (s_data->return_state);
	close_fd(data);
	exit (EXIT_FAILURE);
}

int	piped_built_in(t_data *data, int cmd_num)
{
	pid_t	built_in_pid;

	built_in_pid = fork();
	if (built_in_pid < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(-1);
	}
	else if (built_in_pid == 0)
	{
		exec_pipeline_cmd(data, cmd_num);
		check_redirection(data, cmd_num);
		forked_builtin(data, cmd_num);
		close_fd(data);
	}
	return (1);
}

int	builtin(t_data *data, int cmd_num)
{
	int	i;

	i = s_data->return_state;
	if (ft_cd(data, s_data->envp, cmd_num) \
	|| ft_echo(data, cmd_num) \
	|| ft_pwd(data, cmd_num) \
	|| ft_env(data, s_data->envp, cmd_num) \
	|| ft_unset(data, s_data->envp, cmd_num) \
	|| ft_export(data, s_data->envp, cmd_num))
		return (1);
	else if (ft_exit(data, cmd_num))
		exit (i);
	return (0);
}

