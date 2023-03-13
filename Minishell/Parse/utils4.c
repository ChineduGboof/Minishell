/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:14 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 16:49:07 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_data(t_data *data, char *cmd_holder, t_envp *envp)
{
	data->path = NULL;
	data->env = envp->env;
	data->flag = 0;
	data->cmd_args = cmd_holder;
	if (no_spaces(cmd_holder) == 0)
	{
		print_error("bash: syntax error near unexpected token `|'");
		return (0);
	}
	return (1);
}

char	*copy_parsed_cmd(char *cmd, char *new)
{
	int		i[2];
	char	c;

	i[0] = 0;
	i[1] = 0;
	while (cmd[i[0]])
	{
		if (cmd[i[0]] == 39 || cmd[i[0]] == 34)
		{
			c = cmd[i[0]];
			i[0]++;
			while (cmd[i[0]] != c)
				new[i[1]++] = cmd[i[0]++];
		}
		if (cmd[i[0]] != 39 && cmd[i[0]] != 34 && cmd[i[0]] != 0)
		{
			new[i[1]] = cmd[i[0]];
			i[1]++;
		}
		i[0]++;
	}
	new[i[1]] = 0;
	return (new);
}

char	*allocate_parsed_cmd(char *cmd)
{
	int		i;
	int		j;
	char	c;
	char	*new;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39 || cmd[i] == 34)
		{
			c = cmd[i++];
			while (cmd[i] != c)
			{
				j++;
				i++;
			}
		}
		if (cmd[i] != 39 && cmd[i] != 34 && cmd[i] != 0)
			j++;
		i++;
	}
	new = malloc(j + 1);
	new = copy_parsed_cmd(cmd, new);
	return (new);
}

int	uneven_quotes(char *cmd)
{
	int		i;
	char	c;

	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] == 39 || cmd[i] == 34))
		{
			c = cmd[i];
			i++;
			while (cmd[i] != c)
			{
				if (cmd[i] == 0)
				{
					g_args->dquote = true;
					return (0);
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

char	*check_dquote(char *cmd, t_data *info)
{
	int		i;
	char	c;
	int		flag;
	char	*new;

	i = 0;
	flag = 0;
	while (cmd[i])
	{
		if ((cmd[i] == 39 || cmd[i] == 34))
		{
			flag = 1;
			c = cmd[i];
			i = check_flag(info, i, c);
			i = increment_till_next_quote(cmd, i, c);
		}
		i++;
	}
	if (g_args->dquote == 0 && flag == 1)
		new = allocate_parsed_cmd(cmd);
	else
		return (cmd);
	free(cmd);
	return (new);
}
