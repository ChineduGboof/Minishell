/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:16:49 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 14:16:52 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	edit_pwd(char *old_pwd, char *new_pwd)
{
	del_from_env(s_data->envp, "PWD=");
	del_from_env(s_data->envp, "OLDPWD=");
	add_to_env(s_data->envp, old_pwd);
	add_to_env(s_data->envp, new_pwd);
}

static void	update_path(t_envp *envp)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*pwd_value;
	char	*path;

	pwd_value = get_env_value(envp, "PWD=");
	if (pwd_value)
	{
		path = getcwd(NULL, 0);
		old_pwd = ft_strjoin("OLDPWD", pwd_value);
		new_pwd = ft_strjoin("PWD=", path);
		edit_pwd(old_pwd, new_pwd);
		free(new_pwd);
		free(old_pwd);
		free(path);
		path = NULL;
		new_pwd = NULL;
		old_pwd = NULL;
	}
	if (pwd_value)
	{
		free(pwd_value);
		pwd_value = NULL;
	}
}

int	ft_cd(t_data *data, t_envp *envp, int cmd_num)
{
	if (data[cmd_num].s_cmd[0])
	{
		if (ft_strcmp(data[cmd_num].s_cmd[0], "cd") == 0)
		{
			if (!data[cmd_num].s_cmd[1]
				|| ft_strcmp(data->s_cmd[1], "~") == 0)
				chdir(getenv("HOME"));
			else if (chdir(data[cmd_num].s_cmd[1]) < 0)
				perror(data[cmd_num].s_cmd[1]);
			update_path(envp);
			return (1);
		}
	}
	return (0);
}
