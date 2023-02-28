/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:05:05 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/24 11:20:'\'' by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	incrementer55 => find_rd_pos
	locates the redirection position, ignoring anyone in quotes

*/
int	find_rd_pos(t_data *data, int i)
{
	char	c;

	while ((data->cmd_args[i] != '<' && data->cmd_args[i] != '>')
		&& data->cmd_args[i])
	{
		if ((data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"'))
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

/*
    name => incrementer_3
    checks for single or double quotes, 
    looks for the end of the quotes and returns the position of closing quote
*/
int	pos_of_closing_quotes(int i, t_data *data)
{
	char	c;

	if (data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"')
	{
		c = data->cmd_args[i];
		i++;
		while (data->cmd_args[i] != c)
			i++;
	}
	return (i);
}

/*
	name => count_until_next_op
	loops thru the string looking for the first redirection it sees
	After that, it starts from there looking for the next redirection
	the condition set on the while loop enables 
	that if the position it starts is a redirection,
	it skips that and moves to find the next redirection
	This is helpful in cases of double redirections
	it returns the position of the rd or the lenght of the string
*/
int	find_rd(t_data *data, int i)
{
	char	c;

	while ((data->cmd_args[i] != '<' && data->cmd_args[i] != '>')
		&& data->cmd_args[i])
	{
		if ((data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"'))
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

// int	increment_i(t_data *data, int i)
// {
// 	char	c;

// 	if (data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"')
// 	{
// 		c = data->cmd_args[i];
// 		i++;
// 		while (data->cmd_args[i] != c && data->cmd_args[i])
// 		{
// 			i++;
// 		}
// 		i++;
// 	}
// 	else
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int	increment_j(t_data *data, int i, int j)
// {
// 	char	c;

// 	if (data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"')
// 	{
// 		c = data->cmd_args[i];
// 		i++;
// 		j++;
// 		while (data->cmd_args[i] != c && data->cmd_args[i])
// 		{
// 			i++;
// 			j++;
// 		}
// 		i++;
// 		j++;
// 	}
// 	else
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }


// int	incrementii(t_data *data, int i)
// {
// 	char	c;

// 	c = data->cmd_args[i];
// 	i++;
// 	while (data->cmd_args[i] != c)
// 		i++;
// 	i++;
// 	return (i);
// }

// int	incrementjj(t_data *data, int i, int j)
// {
// 	char	c;

// 	c = data->cmd_args[i];
// 	data->cmd[j] = data->cmd_args[i];
// 	j++;
// 	i++;
// 	while (data->cmd_args[i] != c)
// 	{
// 		data->cmd[j] = data->cmd_args[i];
// 		j++;
// 		i++;
// 	}
// 	data->cmd[j] = data->cmd_args[i];
// 	j++;
// 	i++;
// 	return (j);
// }

// int	incrementer(const char *s, int i)
// {
// 	char	c;

// 	if ((s[i] == '\'' || s[i] == '\"'))
// 	{
// 		c = s[i];
// 		i++;
// 		while (s[i] != c && s[i])
// 			i++;
// 	}
// 	return (i);
// }
