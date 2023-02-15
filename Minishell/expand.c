/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:51:39 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/15 21:05:50 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dup(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free (str);
}

char	**dup_env(char **envp)
{
	int		i;
	int		j;
	char	**dup_env;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	dup_env = malloc(sizeof(char *) * (i + 1));
	if (!dup_env)
		return (NULL);
	while (envp[j])
	{
		dup_env[j] = ft_strdup(envp[j]);
		if (!dup_env[j])
		{
			free_dup(dup_env);
			return (NULL);
		}
		j++;
	}
	dup_env[j] = NULL;
	return(dup_env);
}

/*
	When i is 0, it means a ? was passed and it returns it with any string behind it
	when i is 1, it means a digit or special character comes after the $ sign
	it skips that and joins every other string it sees
*/
char	*var_edge_cases(char *str, int i)
{
	char	*temp;
	char	*temp2;

	temp = (NULL);
	temp2 = (NULL);
	if (i == 0)
	{
		temp = ft_strdup("$");
		temp2 = ft_strdup(str);
		free (str);
		str = ft_strjoin(temp, temp2);
		free (temp2);
		return (str);
	}
	if (i == 1)
	{
		temp = ft_substr(str, 1, ft_strlen(str));
		free (str);
		return (temp);
	}
	return (strdup(""));
}

/*
	checks if the stringis a valid variable name, i.e 
	1. it must start with an alphabet or underscore
	2. It must contain on alphanumeric characters and underscores
*/
char	*var_error(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i] == '?')
		return (var_edge_cases(str, 0));
	if (ft_isdigit(str[i]) == 1
		|| (!ft_isalnum(str[i]) && str[i] != '_' && str[i]))
		return (var_edge_cases(str, 1));
	while (str[i] != '\0' && ft_isalnum(str[i]) == 1 && str[i] != '_')
		i++;
	if (str[i] != 0 && i == 0 && (str[i] == '\"' || str[i] == '\''))
		return (str);
	if (str[i] != '\0' && ft_isalnum(str[i]) == 0 && str[i] != '_')
	{
		tmp = ft_strdup(str);
		free (str);
		str = ft_substr(tmp, i, ft_strlen(str) - i);
		free (tmp);
		return (str);
	}
	free (str);
	return (strdup(""));
}

int	in_squotes(char *s, int i)
{
	char	c;

	if ((s[i] == '\'' || s[i] == '\"'))
	{
		c = s[i];
		i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

/*
	copies the environment path and joins any string to it
*/
char	*join_env(char *var, char *temp, int i, t_list *data)
{
	char	*temp2;
	char	*path;

	temp2 = (NULL);
	path = (NULL);
	temp2 = ft_substr(data->env[i], ft_strlen(var),
			strlen(data->env[i]) - ft_strlen(var));
	path = ft_strjoin(temp2, temp);
	free (temp);
	return (path);
}

/*
	checks if the variable is a valid one
	proof of valid variable => 
	1st character cannot be a digit
	One can only use alphanumeric characters and underscore _
	If 1st character is a digit or if empty return 0
*/
int	is_var_valid(char *var, int i)
{
	if (!var)
		return (0);
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i] != '\0')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			break ;
		i++;
	}
	if (!ft_isalnum(var[i]) && var[i] != '_')
		return (i);
	return (0);
}

// example: str = PATH | data = env
char	*get_env(char *str, t_list *data)
{
	int		i;
	char	*var;
	char	*temp;

	i = 0;
	i = is_var_valid(str, i);
	if (!i)
		return (var_error(str));
	temp = ft_substr(str, i, ft_strlen(str) - i);
	var = ft_substr(str, 0, i + 1);
	free (str);
	var[i] = '=';
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(var, data->env[i], ft_strlen(var)) == 0)
		{
			temp = join_env(var, temp, i, data);
			break ;
		}
		i++;
	}
	free(var);
	return (temp);
}

int	cont_expansion(char *str, int i)
{
	if (str[i] == '\'')
		i = in_squotes(str, i);
	if (str[i] == '$' && str[i + 1] == '?')
		i++;
	if (str[i] && str[i] != '$')
		i++;
	return (i);
}

char	*expand_env(char *str, t_list *data)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*var;

	i = 0;
	temp = NULL;
	temp2 = NULL;
	var = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			temp = ft_substr(str, 0, i);	//get the characters before the $ sign
			printf("temp: %s\n", temp);
			temp2 = ft_substr(str, i + 1, ft_strlen(str) - i);	//get the characters after the $ sign
			printf("temp2: %s\n", temp2);
			var = get_env(temp2, data);	//get the environment path
			printf("var: %s\n", var);
			str = ft_strjoin(temp, var);	//join it with the characters before the $ sign
			printf("str: %s\n", str);
			free (var);
		}
		i = cont_expansion(str, i);
	}
	return (str);
}