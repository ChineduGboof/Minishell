/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:08 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 14:11:21 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		i = skip_quoted_string(s, i);
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

int	measure_string(const char *s, int i, char c)
{
	char	cc;
	int		strl;

	strl = 0;
	while (s[i] != c && s[i])
	{
		if ((s[i] == 39 || s[i] == 34))
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
		strl = measure_string(s, i, c);
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
