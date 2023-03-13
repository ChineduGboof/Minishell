/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:28 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 15:20:26 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_for_no_args(t_data **data)
{
	if (!g_args->args)
	{
		ft_putstr_fd(G"\n Bye Minishell \n"END, 1);
		free_readline();
		free(*data);
		*data = NULL;
		free_env(g_args->envp);
		free(g_args->envp);
		free(g_args);
		exit(0);
	}
}

static void	read_args(t_data **data)
{
	while (1)
	{
		g_args->args = readline("Minishell $: ");
		check_for_no_args(&*data);
		if (ft_strlen(g_args->args) && no_spaces(g_args->args)
			&& g_args->args[0] != '\r' && g_args->args[0] != '\t')
		{
			if (g_args->args && ft_strlen(g_args->args))
				add_history(g_args->args);
			*data = validate(*data);
			if (*data == 0)
			{
				free(*data);
				*data = NULL;
				free_readline();
				continue ;
			}
			free_t_data_members(*data);
			close_fd(*data);
			free(*data);
			*data = NULL;
		}	
		free_readline();
	}
}

int	main(int argc, char **argv, char **environ)
{
	t_data	*data;

	g_args = ft_calloc(1, sizeof(t_shell));
	data = NULL;
	if (argc != 1)
	{
		printf(SYNTAX_ERR_S, argv[1]);
		return (127);
	}
	g_args->return_state = 0;
	trap_signals();
	init_env(environ);
	read_args(&data);
	free_env(g_args->envp);
	free_t_data_members(data);
	close_fd(data);
	free(g_args);
	free(data);
	return (EXIT_SUCCESS);
}
