/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:40:16 by gboof             #+#    #+#             */
/*   Updated: 2023/02/28 19:36:15 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	redirect_all_commands_2 => handle_rd_args
	first we scan all the rd's, check if the have valid filenames
	and allocate memory for them
	Next we copy out all the rd into the rd array
	Then we copy the rd arguments like the filename
	then we allocated memory for the rd and file name
	and we copy them seperately into their various fields
	in the struct
*/

int	redirect_all_commands_2(t_data *data)
{
	int	x;
	int	flag;

	x = 0;
	flag = scan_rd(data);
	if (!flag)
	{
		data->rd = NULL;
		data->op = NULL;
		data->fname = NULL;
		return (0);
	}
	copy_all_rd_args(data);
	sort_rd_n_fname(data);
	while (data->rd[x])
	{
		free(data->rd[x]);
		x++;
	}
	free(data->rd);
	return (1);
}

/*
	redirect_all_commands_1
	it calls the first function to check for rd's and file names
	the function allocates memory for them and copies them into 
	their respective slots
	
*/
int	redirect_all_commands_1(t_data *data)
{
	int	x;
	int	y;

	if (!redirect_all_commands_2(data))
		return (0);
	x = 0;
	if (copy_only_cmd(data))
	{
		x = 0;
		y = count_words(data->cmd, ' ');
		free(data->cmd);
		while (x < y)
		{
			data->s_cmd[x] = check_expand(data->s_cmd[x], data);
			data->s_cmd[x] = uneven_quotes(data->s_cmd[x]);
			x++;
		}
	}
	return (1);
}

/*
	I dont think the else field here is important but lets see
	All command arguments come into this function one by one -
	having been splitted and saved in the double array commands
	The variable data->cmd_args points to the individual array of commands
*/
int	redirect_all_commands(t_data *data)
{
	if (data->cmd_args)
	{
		printf("cmd_args:	%s\n", data->cmd_args);
		if (!redirect_all_commands_1(data))
			return (0);
	}
	else
	{
		error_msg ("syntax error near unexpected token `|'");
		return (0);
	}
	return (1);
}



// // static int	heredoc_stopper(t_data *data, int cmd_num)
// // {
// // 	int	j;

// // 	j = 0;
// // 	if (g_data->i > 1)
// // 		return (0);
// // 	while (data[cmd_num].op[j])
// // 	{
// // 		if (ft_strncoomp(data[cmd_num].op[j], "<<", 2) && cmd_num > 0)
// // 			return (0);
// // 		if (ft_strncoomp(data[cmd_num].op[j], "<<", 2))
// // 		{
// // 			g_data->i++;
// // 			return (1);
// // 		}
// // 		j++;
// // 	}
// // 	return (1);
// // }



//check command => validate
// uneven_quotes => check dquote only
// error => check_error_stats
// check cmd_utils => alloc_data

t_data	*validate(t_data *data)
{
	char	**commands;
	int		i;

	i = -1;
	init_some_values(s_data);
	uneven_quotes(s_data->args, s_data);
	if (!errors(s_data))
		return (0);
	data = alloc_data(data, &commands);
	while (++i < (s_data->n_pipes))
	{
		// printf("commands: %s\n", commands[i]);
		// if (!init_data(&data[i], commands[i], s_data->envp)
		// 	|| !redirect_all_commands(&data[i], &for_all) || \
		// 	!heredoc_stopper(data, i))
		// {
		// 	free_2d_array(commands);
		// 	free_tdata(data);
		// 	return (0);
		// }
		if (!init_data(&data[i], commands[i], s_data->envp)
			|| !redirect_all_commands(&data[i]))
		{
			free_2d_array(commands);
			free_tdata(data);
			return (0);
		}
	}
	free_2d_array(commands);
	return (data);
}