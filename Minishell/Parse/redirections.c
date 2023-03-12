/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_alloc_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:30 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:43:33 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	copy_all_rd_args(t_data *data)
{
	int	nb_of_op;
	int	x;
	int	i;
	int	size_of_full_op;

	i = 0;
	nb_of_op = count_rd(data);
	x = 0;
	while (x < nb_of_op)
	{
		i = find_rd_pos(data, i);
		copy_rd_arg(data, i, x);
		size_of_full_op = get_rd_fname_size(data, i);
		if (size_of_full_op == 0)
			return (0);
		escape_rd(data, &i);
		x++;
	}
	return (0);
}

int	count_rd(t_data *data)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	x = 0;
	i = 1;
	while (data->cmd_args[x])
	{
		x = pos_of_closing_quotes(x, data);
		if ((data->cmd_args[x] == '<' || data->cmd_args[x] == '>') && i)
		{
			i = 0;
			y++;
		}
		else if ((data->cmd_args[x] != '<' && data->cmd_args[x] != '>')
			&& i == 0)
			i = 1;
		x++;
	}
	return (y);
}

void	copy_rd_args2(t_data *data, int i, int j, int x)
{
	char	c;

	while (!ft_isspace(data->cmd_args[i]) && (data->cmd_args[i] != '<'
			&& data->cmd_args[i] != '>') && data->cmd_args[i])
	{
		if (data->cmd_args[i] == 39 || data->cmd_args[i] == 34)
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c)
			{
				data->rd[x][j] = data->cmd_args[i];
				j++;
				i++;
			}
			i++;
		}
		else
		{
			data->rd[x][j] = data->cmd_args[i];
			j++;
			i++;
		}
	}
	data->rd[x][j] = 0;
}

int	copy_rd_arg(t_data *data, int i, int x)
{
	int		j;

	j = 0;
	while ((data->cmd_args[i] == '<' || data->cmd_args[i] == '>')
		&& data->cmd_args[i])
	{
		data->rd[x][j] = data->cmd_args[i];
		i++;
		j++;
	}
	while (ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
		i++;
	data->rd[x][j] = ' ';
	j++;
	copy_rd_args2(data, i, j, x);
	return (0);
}

int	rd_fname_size(t_data *data, int i, int j)
{
	char	c;

	while ((!ft_isspace(data->cmd_args[i])) && data->cmd_args[i]
		&& (data->cmd_args[i] != '<' && data->cmd_args[i] != '>'))
	{
		if (!no_rd_fname2(data, i))
			return (0);
		else if (data->cmd_args[i] == 39 || data->cmd_args[i] == 34)
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c && data->cmd_args[i])
			{
				j++;
				i++;
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}
