/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:39 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 14:57:37 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_rd_fname_size(t_data *data, int i)
{
	int		j;

	j = 0;
	while ((data->cmd_args[i] == '<' || data->cmd_args[i] == '>')
		&& data->cmd_args[i] && j < 2)
	{
		if ((data->cmd_args[i] == '>' && data->cmd_args[i + 1] == '<'))
		{
			printf(SYNTAX_ERR_C, data->cmd_args[i + 1]);
			rl_on_new_line();
			return (0);
		}
		i++;
		j++;
	}
	j++;
	while (ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
		i++;
	if (!no_rd_fname(data, i))
		return (0);
	j = rd_fname_size(data, i, j);
	return (j);
}

int	esc_rd_args(t_data *data, int *i, int j)
{
	char	c;

	while ((!ft_isspace(data->cmd_args[*i])) && data->cmd_args[*i]
		&& (data->cmd_args[*i] != '<' && data->cmd_args[*i] != '>'))
	{
		if (!no_rd_fname2(data, *i))
			return (0);
		else if (data->cmd_args[*i] == 39 || data->cmd_args[*i] == 34)
		{
			c = data->cmd_args[*i];
			(*i)++;
			while (data->cmd_args[*i] != c && data->cmd_args[*i])
			{
				j++;
				(*i)++;
			}
			(*i)++;
		}
		else
		{
			(*i)++;
			j++;
		}
	}
	return (j);
}

int	adjust_i(t_data *data, int i)
{
	char	c;

	if (data->cmd_args[i] == 39 || data->cmd_args[i] == 34)
	{
		c = data->cmd_args[i];
		i++;
		while (data->cmd_args[i] != c && data->cmd_args[i])
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

int	adjust_j(t_data *data, int i, int j)
{
	char	c;

	if (data->cmd_args[i] == 39 || data->cmd_args[i] == 34)
	{
		c = data->cmd_args[i];
		i++;
		j++;
		while (data->cmd_args[i] != c && data->cmd_args[i])
		{
			i++;
			j++;
		}
		i++;
		j++;
	}
	else
	{
		i++;
		j++;
	}
	return (j);
}

int	offset_j(t_data *data, int i, int j, char c)
{
	int	x;

	x = 0;
	if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
	{
		x = esc_rd(data, i);
		i += x;
	}
	else if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
	{
		c = data->cmd_args[i++];
		j++;
		while (data->cmd_args[i++] != c)
			j++;
		i++;
		j++;
	}
	else
	{
		i++;
		j++;
	}
	return (j);
}
