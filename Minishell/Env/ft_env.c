/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:49 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 15:18:52 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_env(char **environ)
{
	g_args->heredoc_count = 0;
	g_args->envp = ft_calloc(1, sizeof(t_envp));
	g_args->envp->env = dup_2darray(environ);
	if (getenv("OLDPWD"))
		del_from_env(g_args->envp, "OLDPWD");
	add_to_env(g_args->envp, "OLDPWD");
	if (env_var_exists(g_args->envp, "SHLVL"))
	{
		g_args->envp->shlvl = ft_atoi(getenv("SHLVL"));
		add_to_shlvl();
		shlvl_edge_cases(g_args->envp);
	}
	else
		add_to_env(g_args->envp, "SHLVL=1");
}

int	ft_env(t_data *data, t_envp *envp, int cmd_num)
{
	int	i;

	i = 0;
	if (ft_strcmp(data[cmd_num].s_cmd[0], "env") == 0)
	{
		while (envp->env[i])
		{
			if (ft_strchr(envp->env[i], '='))
				printf("%s\n", envp->env[i]);
			i++;
		}
		return (1);
	}
	return (0);
}
