/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:18:38 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:14:01 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_2d_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
		array = NULL;
	}
}

void	free_env(t_envp *envp)
{
	int	i;

	if (envp->env != NULL)
	{
		i = 0;
		while (envp->env[i] != NULL)
		{
			free(envp->env[i]);
			envp->env[i] = NULL;
			i++;
		}
		free(envp->env);
		envp->env = NULL;
	}
}

void	free_struct_op(t_data *data, int cmd_num)
{
	int	i;

	i = 0;
	if (data[cmd_num].op)
	{
		while (data[cmd_num].op[i] != NULL)
		{
			free(data[cmd_num].op[i]);
			data[cmd_num].op[i] = NULL;
			i++;
		}
		free(data[cmd_num].op);
		data[cmd_num].op = NULL;
	}
}

void	free_struct_fname(t_data *data, int cmd_num)
{
	int	i;

	i = 0;
	if (data[cmd_num].fname)
	{
		while (data[cmd_num].fname[i] != NULL)
		{
			free(data[cmd_num].fname[i]);
			data[cmd_num].fname[i] = NULL;
			i++;
		}
		free(data[cmd_num].fname);
		data[cmd_num].fname = NULL;
	}
}

void	free_struct_s_cmd(t_data *data, int cmd_num)
{
	int	i;

	i = 0;
	if (data[cmd_num].s_cmd)
	{
		while (data[cmd_num].s_cmd[i] != NULL)
		{
			free(data[cmd_num].s_cmd[i]);
			i++;
		}
		free(data[cmd_num].s_cmd);
	}
}
