/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:52:06 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/01 18:30:45 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	i think if we check for the error of passing a pipe and anoda with nothing inside,
	we can skip this function
	Note* to set the data->env = envp->env; we would need to first initalize the envp 
	in the main else we would get errors
*/
int	init_data(t_data *data, char *commands, t_envp *envp)
{
	// data->path = NULL;   // should have a NULL value due to calloc
	// data->env = envp->env;
	//data->flag = false;
	// data->all = *for_all;
	data->cmd_args = commands;
	if (!no_spaces(commands))
	{
		error_msg ("syntax error near unexpected token `|'");
		return (0);
	}
	return (1);
	(void)envp;
}

/*
	Here we initialize the number of pipes to 1 to account for 2 structs when you see one pipe
	and we set the quote to false
*/
void	init_some_values(void)
{
	s_data->dquote = false;
	s_data->n_pipes = 1;
}

/*
	allocate memory of each struct using the number of pipes
*/
t_data	*alloc_data(t_data *data, char ***commands)
{
	s_data->n_pipes = pipe_stats(s_data->args, s_data->n_pipes);
	data = ft_calloc(sizeof(t_data), (s_data->n_pipes + 1));
	*commands = my_ft_split(s_data->args, '|');
	return (data);
}

/*
	allocate memory for the redirections. 
	redirection type, file names, and complete rd, 

*/
void	alloc_rd(t_data *data, int rd_num)
{
	data->rd = malloc((rd_num + 1) * sizeof(char *));
	data->op = malloc((rd_num + 1) * sizeof(char *));
	data->fname = malloc((rd_num + 1) * sizeof(char *));
	data->rd[rd_num] = NULL;
	data->op[rd_num] = NULL;
	data->fname[rd_num] = NULL;
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