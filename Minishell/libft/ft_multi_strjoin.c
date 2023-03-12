/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:21:52 by gboof             #+#    #+#             */
/*   Updated: 2023/03/11 23:22:58 by gboof            ###   ########.fr       */
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