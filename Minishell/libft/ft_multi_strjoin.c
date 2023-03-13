/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:12:17 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/13 15:12:30 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
	Edited version of ft_strjoin() to join multiple strings together
 */
char	*ft_multi_strjoin(int str_num, ...)
{
	va_list	args;
	char	*str;
	char	*temp;
	char	*joined_str;

	joined_str = ft_strdup("");
	va_start(args, str_num);
	str = va_arg(args, char *);
	while (str_num > 0)
	{
		temp = joined_str;
		joined_str = ft_strjoin(joined_str, str);
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
		str = va_arg(args, char *);
		str_num--;
	}
	va_end(args);
	return (joined_str);
}

/*============================================================================*/