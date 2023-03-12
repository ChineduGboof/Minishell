/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:10:36 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 18:08:40 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The bzero() function writes n zeroed bytes to the string s.
	It writes the '\0' character to n number of bytes(or characters)  
	If n is zero, bzero() does nothing
*/

#include "libft.h"

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
