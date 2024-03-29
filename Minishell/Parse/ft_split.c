/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:21:16 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:09:08 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	alloc_rd(t_data *data, int nb_of_op)
{
	data->rd = malloc((nb_of_op + 1) * sizeof(char *));
	data->op = malloc((nb_of_op + 1) * sizeof(char *));
	data->fname = malloc((nb_of_op + 1) * sizeof(char *));
	data->rd[nb_of_op] = NULL;
	data->op[nb_of_op] = NULL;
	data->fname[nb_of_op] = NULL;
}

int	wordscount(char const *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 1;
	while (s[i])
	{
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

char	*wordscut(char const *s, int len, int start)
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

void	wordsplit(char **strs, char c, char const *s, int words)
{
	int	i;
	int	strl;
	int	word;

	i = 0;
	word = 0;
	strl = 0;
	while (word < words)
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] != c && s[i])
			if (i++ >= 0)
				strl++;
		strs[word++] = wordscut(s, strl, i);
		strl = 0;
	}
	strs[word] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		words;

	if (!s)
		return (0);
	words = wordscount(s, c);
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	wordsplit(a, c, s, words);
	return (a);
}
