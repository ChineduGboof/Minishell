/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:43:27 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/23 12:38:50 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.
	Returns the substring and a NULL if the allocation fails.
	Error Checks:
	1. Check if the string is less than the start location to be copied from
	2. Check if amount of string to be copied is more than the amount
		that can be copied
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	j = 0;
	while (j < len)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
