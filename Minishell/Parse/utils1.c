/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:48 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:47:20 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_quote_i(t_data *data, int i)
{
	char	c;

	c = data->cmd_args[i];
	i++;
	while (data->cmd_args[i] != c)
		i++;
	i++;
	return (i);
}

int	skip_quote_j(t_data *data, int i, int j)
{
	char	c;

	c = data->cmd_args[i];
	data->cmd[j] = data->cmd_args[i];
	j++;
	i++;
	while (data->cmd_args[i] != c)
	{
		data->cmd[j] = data->cmd_args[i];
		j++;
		i++;
	}
	data->cmd[j] = data->cmd_args[i];
	j++;
	i++;
	return (j);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_strlen_n(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	isenv_se(char c)
{
	if (c == '#' || c == '$' || c == '&' || c == '-' || c == '@' || c
		== '!' || c == '*')
		return (1);
	return (0);
}
