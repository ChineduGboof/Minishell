/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:16:40 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 19:38:55 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_and_exit(t_data *data)
{
	ft_putstr_fd("exit", 2);
	free_readline();
	close_fd(data);
	free_t_data_members(data);
	free_env(g_args->envp);
	free(g_args->envp);
	free(g_args);
	free(data);
	data = NULL;
}

static void	print_exit_error(char *str)
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
					print_exit_error(data[cmd_num].s_cmd[1]);
					free_readline();
					close_fd(data);
					free_t_data_members(data);
					free(data);
					return (1);
				}
			}
			g_args->return_state = ft_atoi(data[cmd_num].s_cmd[1]) % 256;
		}
		free_and_exit(data);
		return (1);
	}
	return (0);
}
