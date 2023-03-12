/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:29:00 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 08:46:36 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The isascii() function tests for an ASCII character
	Any character between 0 and 127
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
