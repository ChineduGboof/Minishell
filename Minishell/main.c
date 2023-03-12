/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:28 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:41:02 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	check the control C
*/
#include "minishell.h"

static void	init_env(char **environ)
{
	s_data->heredoc_count = 0;
	s_data->envp = ft_calloc(1, sizeof(t_envp));
	s_data->envp->env = dup_2darray(environ);
	if (getenv("OLDPWD"))
		del_from_env(s_data->envp, "OLDPWD");
	add_to_env(s_data->envp, "OLDPWD");
	if (env_var_exists(s_data->envp, "SHLVL"))
	{
		s_data->envp->shlvl = ft_atoi(getenv("SHLVL"));
		add_to_shlvl();
		shlvl_edge_cases(s_data->envp);
	}
	else
		add_to_env(s_data->envp, "SHLVL=1");
}

void	check_for_no_args(t_data **data)
{
	if (!s_data->args)
	{
		ft_putstr_fd(G"\n Bye Minishell \n"END, 1);
		free_readline();
		free(*data);
		*data = NULL;
		free_env(s_data->envp);
		free(s_data->envp);
		free(s_data);
		exit(0);
	}
}

static void	read_args(t_data **data)
{
	while (1)
	{
		s_data->args = readline("Minishell $: ");
		check_for_no_args(&*data);
		if (ft_strlen(s_data->args) && no_spaces(s_data->args)
			&& s_data->args[0] != '\r' && s_data->args[0] != '\t')
		{
			if (s_data->args && ft_strlen(s_data->args))
				add_history(s_data->args);
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

	s_data = ft_calloc(1, sizeof(t_shell));
	data = NULL;
	if (argc != 1)
	{
		printf(SYNTAX_ERR_S, argv[1]);
		return (127);
	}
	s_data->return_state = 0;
	trap_signals();
	init_env(environ);
	read_args(&data);
	free_env(s_data->envp);
	free_t_data_members(data);
	close_fd(data);
	free(s_data);
	free(data);	
	return (EXIT_SUCCESS);
}

