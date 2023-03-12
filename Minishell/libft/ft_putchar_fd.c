/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:22:50 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 08:33:42 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the character ’c’ to the given file descriptor.
	c: The character to output.
	fd: The file descriptor on which to write.

*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
