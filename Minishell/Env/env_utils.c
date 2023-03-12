/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:15 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 14:14:41 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sizeof_2d_array(char **array)
{
	int	raw;

	raw = 0;
	if (array)
	{
		while (array[raw] != NULL)
			raw++;
	}
	return (raw);
}

char	**dup_2darray(char **array)
{
	int		i;
	int		raws;
	char	**result;

	i = 0;
	raws = sizeof_2d_array(array);
	result = ft_calloc(sizeof(char *), (raws + 1));
	if (!result)
		return (NULL);
	while (i < raws)
	{
		if (array[i])
			result[i] = ft_strdup(array[i]);
		else
			break ;
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	add_to_env(t_envp *envp, char *to_add)
{
	int		i;
	int		raws;
	char	**tmp_env;

	i = 0;
	raws = sizeof_2d_array(envp->env);
	tmp_env = dup_2darray(envp->env);
	free_env(s_data->envp);
	envp->env = ft_calloc(sizeof(char *), (raws + 2));
	while (i < raws)
	{
		envp->env[i] = ft_strdup(tmp_env[i]);
		i++;
	}
	free_2d_array(tmp_env);
	envp->env[i] = ft_strdup(to_add);
	i++;
	envp->env[i] = NULL;
}

void	del_from_env_2(int *new_raws, char ***tmp_env, t_envp *envp)
{
	*new_raws = sizeof_2d_array(envp->env) - 1;
	*tmp_env = dup_2darray(envp->env);
	free_env(envp);
	envp->env = ft_calloc(sizeof(char *), *new_raws + 1);
}

void	del_from_env(t_envp *envp, char *to_delete)
{
	int		i;
	int		j;
	int		new_raws;
	size_t	env_name_len;
	char	**tmp_env;

	i = 0;
	j = 0;
	del_from_env_2(&new_raws, &tmp_env, envp);
	while (i < new_raws + 1)
	{
		env_name_len = get_env_name_len(tmp_env, i);
		if (ft_strncmp(tmp_env[i], to_delete, env_name_len) == 0)
			i++;
		else if (tmp_env[i])
		{
			envp->env[j] = ft_strdup(tmp_env[i]);
			i++;
			j++;
		}
	}
	free_2d_array(tmp_env);
	envp->env[j] = NULL;
}
