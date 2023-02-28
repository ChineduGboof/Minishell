/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:28:10 by gboof             #+#    #+#             */
/*   Updated: 2023/02/24 11:53:15 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i ;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = count * size;
	if (size >= SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < j)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	no_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == 0)
		return (0);
	return (1);
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

void	disp_error(char *str)
{
	printf ("%s", str);
	rl_on_new_line();
}



int	ft_strncoomp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n && s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

void	error_msg(char *str)
{
	printf("\e[0;31m minishell:🔗 %s\n\e[0m", str);
	rl_on_new_line();
}