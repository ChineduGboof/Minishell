/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:26 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/13 15:11:57 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_rd_closer(t_data *data, int cmd_num)
{
	if (data[cmd_num].fd_rd != 0)
	{
		close(data[cmd_num].fd_rd);
		data[cmd_num].fd_rd = 0;
	}
}

void	fd_temp_closer(void)
{
	if (g_args->fd_temp != 0)
	{
		close (g_args->fd_temp);
		g_args->fd_temp = 0;
	}
}

void	close_fd(t_data *data)
{
	int	i;

	i = 0;
	while (i < g_args->n_pipes - 1)
	{
		if (data[i].fd[0] != 0)
		{
			close (data[i].fd[0]);
			data[i].fd[0] = 0;
		}
		if (data[i].fd[1] != 0)
		{
			close (data[i].fd[1]);
			data[i].fd[1] = 0;
		}
		if (data[i].fd_rd != 0)
		{
			close (data[i].fd_rd);
			data[i].fd_rd = 0;
		}
		i++;
	}
	fd_temp_closer();
}

void	free_t_data_members(t_data *data)
{
	int	cmd_num;

	cmd_num = 0;
	while (cmd_num < g_args->n_pipes)
	{
		free_struct_op(data, cmd_num);
		free_struct_fname(data, cmd_num);
		free_struct_s_cmd(data, cmd_num);
		cmd_num++;
	}
}

void	free_readline(void)
{
	g_args->heredoc_count = 0;
	if (g_args->args)
	{
		free(g_args->args);
		g_args->args = NULL;
	}
}
