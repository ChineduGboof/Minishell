/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:35:27 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 17:56:08 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The calloc() functions allocate memory. 
	The allocated memory is aligned such that it can be used for any data typ
	The calloc() function contiguously allocates enough space 
	for count objects that are size bytes of memory each 
	and returns a pointer to the allocated memory.
	The allocated memory is filled with bytes of value zero.
	If successful, calloc() functions returns a pointer to allocated memory.
	If there is an error, they return a NULL pointer
	The free() function does not return a value.
	1. since malloc take both the size you want 
		and the size of the varible as one block
		we take that and create individual blocks for each
		so instead of say 3blocks in one, we have 3 blocks in 1, 2 ,3 
*/
#include "libft.h"

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
