/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:16:40 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 13:19:13 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

static void	exit_utils(t_data *data)
{
	free_readline();
	close_fd(data);
	free_t_data_members(data);
	free_env(s_data->envp);
	free(s_data->envp);
	free(s_data);
	free(data);
	data = NULL;
}

static void	exit_utils_2(char *str)
{
	ft_putstr_fd("[minishell]:", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	s_data->return_state = 255;
	free_env(s_data->envp);
	free(s_data->envp);
	free(s_data);
}

int	ft_exit(t_data *data, int cmd_num)
{
	int	i;

	i = -1;
	if (ft_strcmp(data[cmd_num].s_cmd[0], "exit") == 0)
	{
		if (data[cmd_num].s_cmd[1])
		{
			while (data[cmd_num].s_cmd[1][++i])
			{
				if (!ft_isdigit(data[cmd_num].s_cmd[1][i]))
				{
					exit_utils_2(data[cmd_num].s_cmd[1]);
					free_readline();
					close_fd(data);
					free_t_data_members(data);
					free(data);
					return (1);
				}
			}
			s_data->return_state = ft_atoi(data[cmd_num].s_cmd[1]) % 256;
		}
		exit_utils(data);
		return (1);
	}
	return (0);
}

