/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:22:22 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 10:07:44 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Adds the node ’new’ at the beginning of the list.
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be dded to the list
	1. store the address in list to the new-> next
	2. store the new elements address in list
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
