/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:50:57 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/12 19:04:15 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	Adds a space to each when there characters are found | > >> < << but ignores those in quotes
*/

bool	quote(char c, int pos, int i[])
{
	bool	quote_state;

	quote_state = false;
	if (c == '\"' || c == '\'')
	{
		if (!(i[0]))
		{
			quote_state = true;
			i[0] = c;
			i[1] = pos;
		}
		i[2] = c;
		i[3] = pos;
		if (i[2] == i[0] && i[3] > i[1])
		{
			quote_state = false;
			i[0] = 0;
			i[1] = 0;
		}
	}
	return (quote_state);
}

char *add_space(const char *str)
{
	int		len;
	int		i;
	int		j;
	char	c;
	int		k[4];

	ft_bzero(k, 4 * sizeof(int));
	len = ft_strlen(str);
	char *new_str = malloc(len * 2 + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		c = str[i];
		if ((c == '|') && !quote(c, i, k))
		{
			new_str[j++] = ' ';
			new_str[j++] = c;
			new_str[j++] = ' ';
			i++;
		}
		else if (c == '<' && i + 1 < len && str[i + 1] == '<' && !quote(c, i, k))
		{
			new_str[j++] = ' ';
			new_str[j++] = '<';
			new_str[j++] = '<';
			new_str[j++] = ' ';
			i += 2;
		}
		else if (c == '>' && i + 1 < len && str[i + 1] == '>' && !quote(c, i, k))
		{
			new_str[j++] = ' ';
			new_str[j++] = '>';
			new_str[j++] = '>';
			new_str[j++] = ' ';
			i += 2;
		}
		else if (c == '>' && !quote(c, i, k))
		{
			new_str[j++] = ' ';
			new_str[j++] = '>';
			new_str[j++] = ' ';
			i++;
        }
		else if (c == '<' && !quote(c, i, k))
		{
			new_str[j++] = ' ';
			new_str[j++] = '<';
			new_str[j++] = ' ';
			i++;
		}
		else
		{
			new_str[j++] = c;
			i++;
		}
	}
	new_str[j] = '\0';
	return new_str;
}
