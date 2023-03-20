/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:17:01 by gboof             #+#    #+#             */
/*   Updated: 2023/03/17 14:13:11 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(t_data *data, int cmd_num)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (data[cmd_num].s_cmd[0])
	{
		if (ft_strcmp(data[cmd_num].s_cmd[0], "pwd") == 0)
		{
			ft_putendl_fd(path, 1);
			free(path);
			path = NULL;
			return (1);
		}
	}
	free(path);
	path = NULL;
	return (0);
}
