/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:09 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 14:16:58 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_var_exists(t_envp *envp, char *to_compare)
{
	int	i;
	int	element_len;

	i = 0;
	while (envp->env[i])
	{
		element_len = get_env_name_len(envp->env, i);
		if (ft_strncmp(envp->env[i], to_compare, element_len) == 0)
			return (1);
		i++;
	}
	return (0);
}

size_t	get_env_name_len(char **env, int index)
{
	size_t	i;

	i = 0;
	if (ft_strchr(env[index], '='))
	{
		while (env[index][i] && env[index][i] != '=')
			i++;
	}
	else
		i = ft_strlen(env[index]);
	return (i);
}

char	*get_env_value(t_envp *envp, char *element_name)
{
	char	*value;
	size_t	env_name_len;
	int		i;

	i = 0;
	value = NULL;
	while (envp->env[i])
	{
		env_name_len = get_env_name_len(envp->env, i);
		if (ft_strncmp(envp->env[i], element_name, env_name_len) == 0)
		{
			value = ft_strdup(ft_strchr(envp->env[i], '='));
			break ;
		}
		i++;
	}
	return (value);
}
