/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:01:22 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 08:40:48 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The isdigit() function tests for a decimal digit character
	The isdigit() functions return zero if the character tests false and
	return non-zero if the character tests true
*/

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
