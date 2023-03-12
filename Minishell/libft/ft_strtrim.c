/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:29:38 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/23 14:21:45 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
	Returns the trimmed string and NULL if the allocation fails.
	loop thru the string s1, take its first character 
	and search if its in the list of charaters in set
	if found there, keep moving forward till you dont see a match
	once a match is not found, store the int location
	now search again starting from the end of string s1 backwards
	once no match is found store the location
	when you subtract both locations compensating for the null
	you get the number of characters to be allocated to malloc
	now start printing to malloc starting from the start location
	stop at the end location
*/
#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!(s1))
		return (0);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc (sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
