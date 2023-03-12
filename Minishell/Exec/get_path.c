/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:19:34 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:33:49 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void
	get_path_utils(char ***splitted_path, int *i, \
	t_data *data, char **joined_path)
{
	if (*joined_path)
	{
		free(*joined_path);
		*joined_path = NULL;
	}
	if ((*splitted_path)[*i])
		*joined_path = ft_multi_strjoin(3, (*splitted_path)[*i], \
			"/", data->s_cmd[0]);
}

char
	*find_exec_path(char ***splitted_path, int *i, t_data *data, char **joined_path)
{
	while (*splitted_path && (*splitted_path)[*i])
	{
		if (data->s_cmd && data->s_cmd[0])
			get_path_utils(splitted_path, i, data, joined_path);
		else
			return (NULL);
		if (access(*joined_path, F_OK) == 0)
			return (*joined_path);
		else
		{
			if (*joined_path)
			{
				free(*joined_path);
				*joined_path = NULL;
			}
		}
		(*i)++;
	}
	return ("valid path not found");
}

static void	error_message(t_data *data, int cmd_found)
{
	if (!cmd_found)
	{
		ft_putstr_fd("\033[1;31m [minishell]: \033[0m ", 2);
		ft_putstr_fd(data->s_cmd[0], 2);
		ft_putstr_fd(": command not found\033[0m\n", 2);
		s_data->return_state = 127;
	}
}

char	*get_path(char *path, t_data *data, char *args)
{
	char	**splitted_path;
	char	*joined_path;
	int		cmd_found;
	int		i;

	joined_path = NULL;
	splitted_path = NULL;
	cmd_found = 0;
	if (path && data->s_cmd && data->s_cmd[0] && ft_strlen(args) != 0)
	{
		splitted_path = ft_split(path, ':');
		i = 0;
		if (!ft_strncomp(find_exec_path(&splitted_path, &i, data,
					&joined_path), "valid path not found", 21))
			return (find_exec_path(&splitted_path, &i, data, &joined_path));
		if (splitted_path)
			free_2d_array(splitted_path);
		error_message(data, cmd_found);
	}
	return (NULL);
}

