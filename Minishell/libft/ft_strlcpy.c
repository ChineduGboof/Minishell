/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:52 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/23 08:08:49 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
	NUL-ter-minating the result if dstsize is not 0.
	If the src and dst strings overlap, the behavior is undefined.
	Returns the length of src
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
