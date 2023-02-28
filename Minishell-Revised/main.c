/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:17:03 by gboof             #+#    #+#             */
/*   Updated: 2023/02/28 19:44:43 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Things to track 
	g_data => s_data
	data   => data
	checker => spaces_only
	1. g_data->return_state = 0;
	2. check for signals
	3. work on the environment variable

	stopped at copy_only_cmd
*/

static void	read_args(t_data **data)
{
	while (1)
	{
		s_data->args = readline("Minishell $: ");
		if (!s_data->args)			//takes care of Cntrl D seg fault
			break;
		if (ft_strlen(s_data->args) && no_spaces(s_data->args)		//checks for whitespaces
			&& s_data->args[0] != '\r' && s_data->args[0] != '\t')
		{
			add_history(s_data->args);
			*data = validate(*data);
			if (*data == 0)
			{
				free_tdata(*data);
				free_readline();
				continue;
			}
			free_tdata(*data);
		}
		free_readline();
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	s_data = ft_calloc(1, sizeof(t_shell)); 
	data = NULL;
	if (argc != 1)
	{
		printf(SYNTAX_ERR_S, argv[1]);
		return (1);
	}
	read_args(&data);
	free(s_data);
	return (0);
	(void)envp;
}