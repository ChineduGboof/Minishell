/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:28:37 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 08:35:17 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string ’s’ to the given file descriptor.
	s: The string to output.
	fd: The file descriptor on which to write.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
