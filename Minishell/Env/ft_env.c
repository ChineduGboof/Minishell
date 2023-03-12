/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:49 by gboof             #+#    #+#             */
/*   Updated: 2023/03/11 23:50:47 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
