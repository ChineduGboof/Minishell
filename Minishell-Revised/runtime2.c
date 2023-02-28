/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:23:29 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/28 19:43:47 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		j = skip_j(data, i, j, c);
		i = skip_i(data, i);
	}
	if (j == 0)
		return (0);
	data->cmd = ft_calloc(sizeof(char), j + 1);
	start_copy_cmd(data);
	return (1);
}

int	skip_j(t_data *data, int i, int j, char c)
{
	int	x;

	x = 0;
	if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
	{
		x = skip_op(data, i);
		i += x;
	}
	else if ((data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"'))
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

int	skip_i(t_data *data, int i)
{
	int		x;
	char	c;

	if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
	{
		x = skip_op(data, i);
		i += x;
	}
	else if ((data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"'))
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

// int	skip_op(t_data *data, int i)
// {
// 	int		j;

// 	j = 0;
// 	while ((data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
// 		&& data->cmd_args[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	while (ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	while (!ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
// 	{
// 		j = increment_j(data, i, j);
// 		i = increment_i(data, i);
// 	}
// 	return (j);
// }

/*
	size_op_skip =>esc_rd_args
	this function begins from the filename, moves past it
	moves past any name in quotation marks

*/
int	esc_rd_args(t_data *data, int *i, int j)
{
	char	c;

	while ((!ft_isspace(data->cmd_args[*i])) && data->cmd_args[*i]
		&& (data->cmd_args[*i] != '<' && data->cmd_args[*i] != '>'))
	{
		if (no_rd_fname2(data, *i))
			return (0);
		else if (data->cmd_args[*i] == '\'' || data->cmd_args[*i] == '\"')
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

/*
	skip_oop => escape_rd
	While looping thru the string, skip the rd operator and skip any spaces
	call another function to escape the rd file name
*/
void	escape_rd(t_data *data, int *i)
{
	int		j;

	j = 0;
	while ((data->cmd_args[*i] == '<' || data->cmd_args[*i] == '>')
		&& data->cmd_args[*i] && j < 2)
	{
		(*i)++;
		j++;
	}
	j++;
	while (ft_isspace(data->cmd_args[*i]) && data->cmd_args[*i])
		(*i)++;
	j = esc_rd_args(data, i, j);
}

// int	i_hate_norm(t_data *data, int i, int j, int x)
// {
// 	while (data->cmd_args[i])
// 	{
// 		if (data->cmd_args[i] == '>' || data->cmd_args[i] == '<')
// 		{
// 			x = skip_op(data, i);
// 			i += x;
// 		}
// 		else if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
// 		{
// 			j = incrementjj(data, i, j);
// 			i = incrementii(data, i);
// 		}
// 		else
// 		{
// 			data->cmd[j] = data->cmd_args[i];
// 			i++;
// 			j++;
// 		}
// 	}
// 	return (j);
// }

// void	start_copy_cmd(t_data *data)
// {
// 	int		i;
// 	int		j;
// 	int		x;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	j = i_hate_norm(data, i, j, x);
// 	data->cmd[j] = '\0';
// 	if (data->cmd[0])
// 		data->s_cmd = ft_split_og(data->cmd, ' ');
// }