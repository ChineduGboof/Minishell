/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:32 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 14:57:53 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_rd_pos(t_data *data, int i)
{
	char	c;

	while ((data->cmd_args[i] != '<' && data->cmd_args[i] != '>')
		&& data->cmd_args[i])
	{
		if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c)
			{
				i++;
			}
		}
		i++;
	}
	return (i);
}

int	pos_of_closing_quotes(int x, t_data *data)
{
	char	c;

	if ((data->cmd_args[x] == 39 || data->cmd_args[x] == 34))
	{
		c = data->cmd_args[x];
		x++;
		while (data->cmd_args[x] != c)
		{
			x++;
		}
	}
	return (x);
}

int	no_rd_fname2(t_data *data, int i)
{
	if (data->cmd_args[i] == '<' || data->cmd_args[i] == '>')
	{
		printf(SYNTAX_ERR_C, data->cmd_args[i]);
		g_args->return_state = 258;
		rl_on_new_line();
		return (0);
	}
	return (1);
}

int	no_rd_fname(t_data *data, int i)
{
	if (data->cmd_args[i] == '<' || data->cmd_args[i] == '>'
		|| data->cmd_args[i] == 0)
	{
		printf(SYNTAX_ERR_C, data->cmd_args[i]);
		g_args->return_state = 258;
		rl_on_new_line();
		return (0);
	}
	return (1);
}

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
