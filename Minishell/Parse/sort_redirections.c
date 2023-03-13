/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_rd_n_fnamename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:48 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:51:32 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sort_rd_n_fname(t_data *data)
{
	int	nb_of_op;
	int	x;

	x = 0;
	nb_of_op = count_rd(data);
	while (x < nb_of_op)
	{
		alloc_rd_n_fname(data, x);
		copy_rd_n_fname(data, x);
		x++;
	}
	return (0);
}

void	alloc_rd_n_fname(t_data *data, int x)
{
	int	i;
	int	size_for_op;
	int	size_for_file;

	i = 0;
	size_for_op = 0;
	size_for_file = 0;
	while (data->rd[x][i] == '>' || data->rd[x][i] == '<')
	{
		i++;
		size_for_op++;
	}
	data->op[x] = malloc(size_for_op + 1);
	i++;
	while (data->rd[x][i])
	{
		i++;
		size_for_file++;
	}
	data->fname[x] = malloc(size_for_file + 1);
}

void	copy_rd_n_fname(t_data *data, int x)
{
	int	i;
	int	size_for_op;
	int	size_for_file;

	i = 0;
	size_for_op = 0;
	size_for_file = 0;
	while (data->rd[x][i] == '>' || data->rd[x][i] == '<')
	{
		data->op[x][size_for_op] = data->rd[x][i];
		i++;
		size_for_op++;
	}
	data->op[x][size_for_op] = 0;
	i++;
	while (data->rd[x][i])
	{
		data->fname[x][size_for_file] = data->rd[x][i];
		i++;
		size_for_file++;
	}
	data->fname[x][size_for_file] = 0;
}

static void	utils(char **to_expand, char **expanded, int i, char **cmd)
{
	if (*to_expand)
	{
		free(*to_expand);
		*to_expand = NULL;
	}
	if (*expanded && (*cmd)[i] == '?')
	{
		free(*expanded);
		*expanded = NULL;
	}
	free(*cmd);
	*cmd = NULL;
}

char	*replace_sub_str_to_expand(char *cmd, int start, int length, char **env)
{
	int		i;
	char	*new_str;
	char	*to_expand;
	char	*expanded;

	i = start;
	new_str = NULL;
	to_expand = ft_strndup(cmd, length, i);
	if (cmd[i] == '?')
		expanded = ft_itoa(g_args->return_state);
	else
		expanded = ft_getenv(to_expand, env);
	if (expanded == NULL)
	{
		if (to_expand)
		{
			free(to_expand);
			to_expand = NULL;
		}
		return (no_expand_found(&cmd, start, length));
	}
	if (expanded)
		new_str = edit_expanded(expanded, cmd, length, start);
	utils(&to_expand, &expanded, i, &cmd);
	return (new_str);
}
