/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:16:40 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 15:07:11 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	exit_utils(t_data *data)
{
	free_readline();
	close_fd(data);
	free_t_data_members(data);
	free_env(g_args->envp);
	free(g_args->envp);
	free(g_args);
	free(data);
	data = NULL;
}

static void	exit_utils_2(char *str)
{
	ft_putstr_fd("[minishell]:", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_args->return_state = 255;
	free_env(g_args->envp);
	free(g_args->envp);
	free(g_args);
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
			g_args->return_state = ft_atoi(data[cmd_num].s_cmd[1]) % 256;
		}
		exit_utils(data);
		return (1);
	}
	return (0);
}
