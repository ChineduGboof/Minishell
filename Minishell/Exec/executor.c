/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:07 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 17:28:16 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_children(void)
{
	while (waitpid(-1, &s_data->return_state, 0) > -1)
		s_data->return_state = WEXITSTATUS(s_data->return_state);
}

static int	setup_pipe(t_data *data, int cmd_num)
{
	if (cmd_num + 1 != s_data->n_pipes)
	{
		if (pipe(data[cmd_num].fd) == -1)
		{
			perror("\033[1;31m [minishell] \033[0m");
			exit(EXIT_FAILURE);
		}
		return (1);
	}
	return (0);
}

static void	start_executing(t_data *data)
{
	int	cmd_num;

	cmd_num = 0;
	while (cmd_num < s_data->n_pipes)
	{
		setup_pipe(data, cmd_num);
		if (s_data->n_pipes > 1)
		{
			if (builtin_checker(data, cmd_num))
			{
				piped_built_in(data, cmd_num);
				cmd_num++;
				continue ;
			}
		}
		else if (data[cmd_num].s_cmd && builtin_checker(data, cmd_num))
		{
			check_redirection(data, cmd_num);
			builtin(data, cmd_num);
			cmd_num++;
			continue ;
		}
		fork_child(data, cmd_num);
		cmd_num++;
	}
}

int	execute(t_data *data)
{
	s_data->fd_temp = dup(STDOUT_FILENO);
	start_executing(data);
	dup2(s_data->fd_temp, STDOUT_FILENO);
	close_fd(data);
	wait_children();
	return (1);
}
