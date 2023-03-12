/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:18:09 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 14:17:10 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shlvl_edge_cases(t_envp *envp)
{
	char	*shlvl;

	if (envp->shlvl == 999)
	{
		del_from_env(envp, "SHLVL=");
		add_to_env(envp, "SHLVL=");
	}
	else if (envp->shlvl == 1000)
	{
		del_from_env(envp, "SHLVL=");
		add_to_env(envp, "SHLVL=");
	}
	else if (envp->shlvl > 999)
	{
		shlvl = get_env_value(envp, "SHLVL");
		ft_putstr_fd("[minishell]: warning: shell level (", STDOUT_FILENO);
		ft_putstr_fd(shlvl + 1, STDOUT_FILENO);
		ft_putendl_fd(") too high, ENDting to 1", STDOUT_FILENO);
		del_from_env(envp, "SHLVL=");
		add_to_env(envp, "SHLVL=1");
		free(shlvl);
		shlvl = NULL;
	}
}

void	add_to_shlvl(void)
{
	char	*shell_level;
	char	*shl;

	s_data->envp->shlvl += 1;
	shl = ft_itoa(s_data->envp->shlvl);
	del_from_env(s_data->envp, "SHLVL=");
	shell_level = ft_strjoin("SHLVL=", shl);
	free(shl);
	shl = NULL;
	add_to_env(s_data->envp, shell_level);
	free(shell_level);
	shell_level = NULL;
}
