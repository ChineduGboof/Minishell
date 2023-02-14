/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:58:09 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:45 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int split_string(char *str, char ***words)
{
	int i;
	int j;
	int wc;
	int wlen;
	int slen;
	bool in_s_quotes;
	bool in_d_quotes;

	i = 0;
	wc = 0;
	wlen = 0;
	in_s_quotes = false;
	in_d_quotes = false;
	slen = ft_strlen(str);
	while (i <= slen)
	{
		if (str[i] == '\'' && !in_d_quotes)
			in_s_quotes = !in_s_quotes;
		else if (str[i] == '\"' && !in_s_quotes)
			in_d_quotes = !in_d_quotes;
		else if (str[i] == ' ' && !in_s_quotes && !in_d_quotes)
			wc++;
		i++;
	}
	*words = (char **) malloc((wc + 1) * sizeof(char *));
	j = 0;
	while (j <= wc)
		(*words)[j++] = (char *) malloc((slen + 1) * sizeof(char));

	i = 0;
	wc = 0;
	wlen = 0;
	in_s_quotes = false;
	in_d_quotes = false;
	while (i <= slen)
	{
		if (str[i] == '\'' && !in_d_quotes)
			in_s_quotes = !in_s_quotes;
		else if (str[i] == '\"' && !in_s_quotes)
			in_d_quotes = !in_d_quotes;
		else if (str[i] == ' ' && !in_s_quotes && !in_d_quotes)
		{
			(*words)[wc][wlen] = '\0';
			wc++;
			wlen = 0;
		}
		else
			(*words)[wc][wlen++] = str[i];
		i++;
	}
	if ((*words)[wc][wlen - 1] != '\0')
		(*words)[wc][wlen] = '\0';
	return wc + 1;
}

void remove_spaces(char *str)
{
	int i;
	int j;
	int in_s_quotes;
	int in_d_quotes;

	i = 0;
	j = 0;
	in_s_quotes = 0;
	in_d_quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			str[j++] = str[i];
			in_s_quotes = !in_s_quotes;
		}
		else if (str[i] == '"')
		{
			str[j++] = str[i];
			in_d_quotes = !in_d_quotes;
		}
		else if (str[i] == ' ' && (!in_s_quotes && !in_d_quotes))
		{
			if (str[i + 1] != ' ')
				str[j++] = str[i];
		} else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}
