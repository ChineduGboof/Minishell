/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:53 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 18:09:51 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memchr() function locates the first occurrence of c 
	(converted to an unsigned char) in string s.
	The memchr() function returns a pointer to the byte located, 
	or NULL if no such byte exists within n bytes.
	n -> determines how many bytes or characters to be analyzed
	beginning from the first byte
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
