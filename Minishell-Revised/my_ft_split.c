/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:39:31 by melsahha          #+#    #+#             */
/*   escape2d: 2023/02/20 21:16:54 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	escape(const char *s, int i)
{
	char	c;

	if ((s[i] == 39 || s[i] == 34))
	{
		c = s[i];
		i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}



int	count_words(char const *s, char c)
{
	int		i;
	int		words;
	int		flag;

	i = 0;
	words = 0;
	flag = 1;
	while (s[i])
	{
		i = escape(s, i);
		if (s[i] == c && !flag)
			flag = 1;
		else if (s[i] != c && flag)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}

char	*trim_word(char const *s, int len, int start)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(len + 1);
	if (!c)
		return (0);
	while (len > 0)
	{
		c[i++] = s[start - len];
		len--;
	}
	c[i] = '\0';
	return (c);
}

int	escape2(const char *s, int i, char c)
{
	char	cc;
	int		strl;

	strl = 0;
	while (s[i] != c && s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"'))
		{
			cc = s[i];
			strl++;
			i++;
			while (s[i] != cc && s[i])
			{
				i++;
				strl++;
			}
		}
		if (i++ >= 0)
			strl++;
	}
	return (strl);
}

void	split_words(char **strs, char c, char const *s, int words)
{
	int		i;
	int		strl;
	int		word;

	i = 0;
	word = 0;
	strl = 0;
	while (word < words)
	{
		while (s[i] && s[i] == c)
			++i;
		strl = escape2(s, i, c);
		i += strl;
		strs[word++] = trim_word(s, strl, i);
		strl = 0;
	}
	strs[word] = 0;
}

char	**my_ft_split(char const *s, char c)
{
	char	**a;
	int		words;

	if (!s)
		return (0);
	words = count_words(s, c);
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	split_words(a, c, s, words);
	return (a);
}