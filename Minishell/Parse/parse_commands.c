/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:40 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 17:07:19 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	esc_rd(t_data *data, int i)
{
	int		j;

	j = 0;
	while ((data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
		&& data->cmd_args[i])
	{
		i++;
		j++;
	}
	while (ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
	{
		i++;
		j++;
	}
	while (!ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
	{
		j = adjust_j(data, i, j);
		i = adjust_i(data, i);
	}
	return (j);
}

int	offset_i(t_data *data, int i)
{
	int		x;
	char	c;

	if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
	{
		x = esc_rd(data, i);
		i += x;
	}
	else if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
	{
		c = data->cmd_args[i];
		i++;
		while (data->cmd_args[i] != c)
		{
			i++;
		}
		i++;
	}
	else
	{
		i++;
	}
	return (i);
}

int	copy_only_cmd(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	while (data->cmd_args[i])
	{
		j = offset_j(data, i, j, c);
		i = offset_i(data, i);
	}
	if (j == 0)
		return (0);
	data->cmd = ft_calloc(sizeof(char), j + 1);
	copy_cmd_to_array(data);
	return (1);
}

int	copy_and_split_cmd(t_data *data, int i, int j, int x)
{
	while (data->cmd_args[i])
	{
		if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
		{
			x = esc_rd(data, i);
			i += x;
		}
		else if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
		{
			j = skip_quote_j(data, i, j);
			i = skip_quote_i(data, i);
		}
		else
		{
			data->cmd[j] = data->cmd_args[i];
			i++;
			j++;
		}
	}
	return (j);
}

void	copy_cmd_to_array(t_data *data)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	j = copy_and_split_cmd(data, i, j, x);
	data->cmd[j] = '\0';
	if (data->cmd[0])
		data->s_cmd = my_ft_split(data->cmd, ' ');
}

