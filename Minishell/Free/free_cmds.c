/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_data_members.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:18:31 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 13:17:27 by gboof            ###   ########.fr       */
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
	if (s_data->fd_temp != 0)
	{
		close (s_data->fd_temp);
		s_data->fd_temp = 0;
	}
}

void	close_fd(t_data *data)
{
	int	i;

	i = 0;
	while (i < s_data->n_pipes - 1)
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
	while (cmd_num < s_data->n_pipes)
	{
		free_struct_op(data, cmd_num);
		free_struct_fname(data, cmd_num);
		free_struct_s_cmd(data, cmd_num);
		cmd_num++;
	}
}

void	free_readline(void)
{
	s_data->heredoc_count = 0;
	if (s_data->args)
	{
		free(s_data->args);
		s_data->args = NULL;
	}
}

