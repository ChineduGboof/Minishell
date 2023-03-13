/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:42 by gboof             #+#    #+#             */
/*   Updated: 2023/03/13 14:46:34 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_env_value(t_envp *envp, char *new_cmd)
{
	int		i;
	size_t	env_name_len;
	char	*temp;

	i = 0;
	while (envp->env[i])
	{
		env_name_len = get_env_name_len(envp->env, i);
		if (ft_strncmp(envp->env[i], new_cmd, env_name_len) == 0)
		{
			temp = ft_strdup(envp->env[i]);
			free(envp->env[i]);
			if (!ft_strchr(temp, '='))
				envp->env[i] = ft_multi_strjoin(3, temp, "=",
						ft_strchr(new_cmd, '=') + 1);
			else
				envp->env[i] = ft_strjoin(temp, ft_strchr(new_cmd, '=') + 1);
			free(temp);
			temp = NULL;
			break ;
		}
		i++;
	}
}

int	export_error(char *err_cmd)
{
	ft_putstr_fd("[minishell]: export: `", 2);
	ft_putstr_fd(err_cmd, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	g_args->return_state = 1;
	return (1);
}

int	already_exist(char *to_add, t_envp *envp)
{
	int		i;
	size_t	env_name_len;

	i = 0;
	while (envp->env[i])
	{
		env_name_len = get_env_name_len(envp->env, i);
		if (ft_strncmp(envp->env[i], to_add, env_name_len) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	plus_checker(t_data *data, int n)
{
	size_t	i;

	i = 0;
	while (data->s_cmd[n] && data->s_cmd[n][i] != '=')
	{
		if (data->s_cmd[n][i] == '+' && data->s_cmd[n][i + 1] == '=')
			return (2);
		else if ((data->s_cmd[n][i] == '+' && data->s_cmd[n][i + 1] != '=')
			&& export_error(data->s_cmd[n]))
			return (0);
		if (ft_isalnum(data->s_cmd[n][i]))
			i++;
		else
		{
			export_error(data->s_cmd[n]);
			return (0);
		}
	}
	if (data->s_cmd[n][i] == '=' && data->s_cmd[n][i + 1])
		return (1);
	return (1);
}

int	valid_toadd(t_data *data, int n)
{
	if (!ft_isalpha(data->s_cmd[n][0]) && export_error(data->s_cmd[n]))
		return (0);
	else if (ft_strchr(data->s_cmd[n], '='))
	{
		if (plus_checker(data, n) == 2)
			return (2);
		else if (!plus_checker(data, n))
			return (0);
		else
			return (1);
	}
	else if (ft_strchr(data->s_cmd[n], '+') && export_error(data->s_cmd[n]))
		return (0);
	return (1);
}
