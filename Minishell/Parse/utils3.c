/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:08 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 16:50:24 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_flag(t_data *info, int i, char c)
{
	if (c == 39)
		info->flag = 1;
	else
		info->flag = 0;
	i++;
	return (i);
}

int	increment_till_next_quote(char *cmd, int i, char c)
{
	while (cmd[i] != c)
	{
		if (cmd[i] == 0)
		{
			g_args->dquote = 1;
			return (0);
		}
		i++;
	}
	return (i);
}

int	find_rd(t_data *data, int i)
{
	char	c;

	while ((data->cmd_args[i] != '<' && data->cmd_args[i] != '>')
		&& data->cmd_args[i])
	{
		if ((data->cmd_args[i] == 39 || data->cmd_args[i] == 34))
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c && data->cmd_args[i])
				i++;
			i++;
		}
		else
			i++;
	}
	return (i);
}

int	no_spaces(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || !cmd[0])
		return (0);
	while (ft_isspace(cmd[i]) && cmd[i])
		i++;
	if (cmd[i] == 0)
		return (0);
	return (1);
}

void	print_error(char *s)
{
	printf("%s\n", s);
	rl_on_new_line();
}
