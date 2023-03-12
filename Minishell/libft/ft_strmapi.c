/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:44 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 08:30:33 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function ’f’ to each character of the
	string ’s’, and passing its index as first argument
	to create a new string (with malloc(3)) resulting
	from successive applications of ’f’.
	s: The string on which to iterate.
	f: The function to apply to each character.
	Returns the string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				n;
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!(s))
		return (0);
	n = ft_strlen(s) + 1;
	if (!s)
		return (0);
	ptr = (char *) malloc(sizeof(char) * n);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
