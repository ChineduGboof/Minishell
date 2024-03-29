/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:08 by gboof             #+#    #+#             */
/*   Updated: 2023/03/18 21:13:31 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_ap_redirection(t_data *data, int cmd_num, int i)
{
	data[cmd_num].fd_rd = ft_open_ap(data[cmd_num].fname[i]);
	if (dup2(data[cmd_num].fd_rd, STDOUT_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	fd_rd_closer(data, cmd_num);
}

void	check_rp_redirection(t_data *data, int cmd_num, int i)
{
	data[cmd_num].fd_rd = ft_open_rp(data[cmd_num].fname[i]);
	if (dup2(data[cmd_num].fd_rd, STDOUT_FILENO) < 0)
	{
		perror("\033[1;31m [minishell] \033[0m");
		exit(EXIT_FAILURE);
	}
	fd_rd_closer(data, cmd_num);
}

int	check_redirection_utils(t_data *data, int cmd_num)
{
	int	i;
	int	stop;

	i = 0;
	stop = -1;
	while (data[cmd_num].op[i])
		i++;
	while (i)
	{
		if (my_strncmp(data[cmd_num].op[i], "<<", 2))
		{
			stop = i;
			break ;
		}
		i--;
	}
	if (my_strncmp(data[cmd_num].op[i], "<<", 2))
	{
		stop = i;
	}
	return (stop);
}

static void	here_doc_redi(t_data *data, int cmd_num)
{
	int	stop;
	int	i;

	stop = check_redirection_utils(data, cmd_num);
	i = 0;
	while (data[cmd_num].op[i])
	{
		if (my_strncmp(data[cmd_num].op[i], "<<", 2))
		{
			if (i != stop)
				ft_here_doc_2(data[cmd_num].fname[i]);
			else
				heredoc_exec(&data[cmd_num], data[cmd_num].fname[i] \
					, cmd_num);
		}
		i++;
	}
}

int	check_redirection(t_data *data, int cmd_num)
{
	int	i;

	here_doc_redi(data, cmd_num);
	i = 0;
	while (data[cmd_num].op[i])
	{
		if (my_strncmp(data[cmd_num].op[i], ">>", 2))
			check_ap_redirection(data, cmd_num, i);
		else if (my_strncmp(data[cmd_num].op[i], ">", 1))
			check_rp_redirection(data, cmd_num, i);
		else if (my_strncmp(data[cmd_num].op[i], "<", 1))
		{
			data[cmd_num].fd_rd = ft_open(data[cmd_num].fname[i]);
			if (dup2(data[cmd_num].fd_rd, STDIN_FILENO) < 0)
			{
				perror("\033[1;31m [minishell] \033[0m");
				exit(EXIT_FAILURE);
			}
			fd_rd_closer(data, cmd_num);
		}
		i++;
	}
	return (1);
}
