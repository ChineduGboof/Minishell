/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:52:42 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/23 12:18:06 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strdup() function allocates sufficient memory for a copy of the string s1, 
	does the copy, and returns a pointer to it.  
	The pointer may subsequently be used as an argument to the function free(3)
	If insufficient memory is available, NULL is returned
	The strndup() function copies at most n characters from the string s1 
	always NUL terminating the copied string.
	add 1 to the size of the string to account for the NULL terminator
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
