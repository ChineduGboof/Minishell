/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:30:34 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/23 14:33:58 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_getenv(char *name, char **env)
// {
// 	int		i;
// 	char	*end_name;

// 	i = 0;
// 	end_name = malloc(ft_strlen(name) + 2);
// 	while (name[i])
// 	{
// 		end_name[i] = name[i];
// 		i++;
// 	}
// 	end_name[i] = '=';
// 	i++;
// 	end_name[i] = 0;
// 	i = 0;
// 	while (env[i] && ft_strncomp(end_name, env[i], ft_strlen_n(end_name)) == 0)
// 		i++;
// 	free(end_name);
// 	if (env[i] != 0)
// 		return (env[i]);
// 	else
// 		return (NULL);
// }


// char	*check_expand_1(int i, char *final_expanded, char **env)
// {
// 	int	start;
// 	int	size_of_name;

// 	start = i;
// 	size_of_name = 0;
// 	if (ft_isdigit(final_expanded[i]) || final_expanded[i] == '?')
// 		size_of_name++;
// 	else
// 	{
// 		while (isenv(final_expanded[i]))
// 		{
// 			size_of_name++;
// 			i++;
// 		}
// 	}
// 	final_expanded = replace_sub_str_to_expand
// 		(final_expanded, start, size_of_name, env);
// 	return (final_expanded);
// }


// char	*check_expand_helper_0(char *final_expanded, int *i, t_data *data)
// {
// 	while (final_expanded[i[0]] != (char)i[1] && final_expanded[i[0]])
// 	{
// 		if (final_expanded[i[0]] == '$' && isenv(final_expanded[i[0] + 1]))
// 		{
// 			i[0]++;
// 			final_expanded = check_expand_1(i[0], final_expanded, data->env);
// 			i[0] = i[2];
// 		}
// 		else
// 			i[0]++;
// 	}
// 	return (final_expanded);
// }

// int	check_expand_helper_01(char *final_expanded, int *i, t_data *data)
// {
// 	while (final_expanded[i[0]] != (char)i[1] && final_expanded[i[0]])
// 	{
// 		if (final_expanded[i[0]] == '$' && isenv(final_expanded[i[0] + 1]))
// 		{
// 			i[0]++;
// 			final_expanded = check_expand_1(i[0], final_expanded, data->env);
// 			i[0] = i[2];
// 		}
// 		else
// 			i[0]++;
// 	}
// 	return (i[0]);
// }


// int	check_expand_helper_1(char *final_expanded, int *i)
// {
// 	i[1] = 39;
// 	i[0]++;
// 	while (final_expanded[i[0]] != (char)i[1] && final_expanded[i[0]])
// 		i[0]++;
// 	i[0]++;
// 	return (i[0]);
// }

// char	*check_expand(char *cmd, t_data *data)
// {
// 	int		i[3];
// 	char	*final_expanded;

// 	i[0] = 0;
// 	if (!checker(cmd))
// 		return (NULL);
// 	final_expanded = cmd;
// 	final_expanded = check_expand_helper_final(final_expanded, i, data);
// 	return (final_expanded);
// }