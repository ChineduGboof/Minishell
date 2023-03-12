/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:42:42 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/20 16:06:01 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Returns the last node of the list.
	lst: The beginning of the list
	Returns the Last node of the list
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
