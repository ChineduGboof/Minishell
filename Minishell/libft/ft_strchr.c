/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:54:30 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 09:26:38 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strchr() function locates the first occurrence 
	of c (converted to a char) in the string pointed to by s.
	The functions strchr() and strrchr() return a pointer 
	to the located character, or NULL if the character 
	does not appear in the string.
	The terminating null character is considered to be part of the string;
	therefore if c is `\0', the func-tions locate the terminating `\0'.
	NOTE->the repeating if statement is to detect the null
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (0);
}
