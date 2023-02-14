/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:16 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/12 20:50:12 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!(str1 && str2))
		return (0);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		ptr[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		ptr[i + j] = str2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!to_find && to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && (str[i + j] != '\0'))
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

// static int	count_words(char *s, char c)
// {
// 	int	res;
// 	int	i;
// 	int	k[4];

// 	ft_bzero(k, 4 * sizeof(int));
// 	i = 0;
// 	res = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c && !quote(s[i], i, k))
// 			i++;
// 		if (s[i] && s[i] != c && !quote(s[i], i, k))
// 			res++;
// 		while (s[i] && s[i] != c && !quote(s[i], i, k))
// 			i++;
// 	}
// 	// printf("num of words: %d\n", res);
// 	return (res);
// }