/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:25:03 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 09:47:28 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strrchr() function locates the last occurrence 
	of c (converted to a char) in the string pointed to by s.
	The functions returns a pointer to the located character,
	or NULL if the character does not appear in the string.
	The terminating null character is considered to be part of the string;
	therefore if c is `\0', the func-tions locate the terminating `\0'.
	Note-> 1 is added to the string length so that the null character is checked
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (char) c)
			return ((char *)s + i);
	return (NULL);
}
