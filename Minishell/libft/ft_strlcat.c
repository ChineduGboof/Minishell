/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:11:09 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/23 11:17:55 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	strlcat() appends string src to the end of dst.  
	It will append at most dstsize - strlen(dst) - 1 characters.  
	It will then NUL-terminate, unless dstsize is 0 or
	the original dst string was longer than dstsize
	return the total length of the string they tried to create
	that means the initial length of dst plus the length of src
	dstsize is total size of final outcome plus null
	If the return value is >= dstsize, the output string has been truncated
	-- calculate the length of the source
	--add the dest to src(chk the null) and add the null
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
	{
		while (src[j] && (dst_len + j) < dstsize)
			dst[i++] = src[j++];
		if ((dst_len + j) == dstsize && dst_len < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (src_len + dst_len);
	}
}
