/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 07:43:21 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 08:49:27 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	checks if the integer passed matches an alphabet in the ascii code
	The isalpha() function returns zero if the character tests false and
	returns non-zero if the character tests true
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
