/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:08:37 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/13 15:08:56 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	redirect_output(t_data *data, int cmd_num)
{
	if (dup2(data[cmd_num].fd[1], STDOUT_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	close(data[cmd_num].fd[1]);
	data[cmd_num].fd[1] = 0;
}

static void	redirect_input(t_data *data, int cmd_num)
{
	if (dup2(data[cmd_num - 1].fd[0], STDIN_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	close(data[cmd_num - 1].fd[0]);
	data[cmd_num - 1].fd[0] = 0;
}

static void	redirect_io(t_data *data, int cmd_num)
{
	if (dup2(data[cmd_num - 1].fd[0], STDIN_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	if (dup2(data[cmd_num].fd[1], STDOUT_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	close(data[cmd_num - 1].fd[0]);
	close(data[cmd_num].fd[1]);
	data[cmd_num - 1].fd[0] = 0;
	data[cmd_num].fd[1] = 0;
}

void	exec_pipeline_cmd(t_data *data, int cmd_num)
{
	if (g_args->n_pipes != 1)
	{
		if (cmd_num == 0)
			redirect_output(data, cmd_num);
		else if (cmd_num + 1 == g_args->n_pipes)
			redirect_input(data, cmd_num);
		else
			redirect_io(data, cmd_num);
	}
}
