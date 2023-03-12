/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:41:01 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/22 09:00:41 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The toupper() function converts a lower-case letter 
	to the corresponding upper-case letter.
	If the argument is a lower-case letter, the toupper() function
	returns the corre-sponding upper-case letter 
	Otherwise, the argument is returned unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
