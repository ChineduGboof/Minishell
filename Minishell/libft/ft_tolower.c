/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:49:24 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 09:04:00 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The tolower() function converts an upper-case letter 
	to the corresponding lower-case letter.
	If the argument is an upper-case letter,
	the tolower() function returns the corre-sponding lower-case letter 
	if there is one; otherwise, the argument is returned unchanged.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
