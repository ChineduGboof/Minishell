/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:34:16 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 08:36:24 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string ’s’ to the given file descriptor
	followed by a newline.

*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
