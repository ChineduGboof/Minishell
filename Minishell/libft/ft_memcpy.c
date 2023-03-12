/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:03 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 18:09:11 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memcpy() function copies n bytes from memory area src to memory area dst.
	The memcpy() function returns the original value of dst.
	If dst and src overlap, behavior is undefined.
	It copies n number of characters from src to dest. 
	if source & destination are same or same address or n not specified,
	return the whole dest, as there is nothing to copy.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
