/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:16:54 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 19:06:49 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_echo_flag(char *cmd)
{
	int		i;

	i = 0;
	if (cmd[i] == '-' && cmd[i + 1] != 'n')
		return (1);
	if (cmd[i] != '-')
		return (1);
	i++;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

static void	detect_dollar(t_data *data, int i, int cmd_num)
{
	int	j;

	j = 0;
	while (data[cmd_num].s_cmd[i][j])
	{
		if (data[cmd_num].s_cmd[i][j] == '$'
			&& data[cmd_num].s_cmd[i][j + 1] == '?')
		{
			ft_putnbr_fd(g_args->return_state, 1);
			g_args->return_state = 0;
			j++;
		}
		else if (data[cmd_num].s_cmd[i][j])
			ft_putchar_fd(data[cmd_num].s_cmd[i][j], 1);
		j++;
	}
}

static void	detect_flag(t_data *data, int *cmd_num, int *i, int *newline)
{
	while (data[*cmd_num].s_cmd[*i]
		&& !is_echo_flag(data[*cmd_num].s_cmd[*i]))
	{
		*newline = 1;
		(*i)++;
	}
}

int	ft_echo(t_data *data, int cmd_num)
{
	int	i;
	int	newline;

	i = 1;
	newline = 0;
	if (strcmp(data[cmd_num].s_cmd[0], "echo") == 0)
	{
		detect_flag(data, &cmd_num, &i, &newline);
		while (data[cmd_num].s_cmd[i])
		{
			detect_dollar(data, i, cmd_num);
			if (data[cmd_num].s_cmd[i + 1])
				ft_putstr_fd(" ", 1);
			i++;
		}
		if (!newline)
			ft_putstr_fd("\n", 1);
		g_args->return_state = 0;
		return (1);
	}
	return (0);
}
