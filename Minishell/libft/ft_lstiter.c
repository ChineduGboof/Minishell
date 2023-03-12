/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:03:55 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/20 17:51:47 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
