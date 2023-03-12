/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:13:13 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/24 14:09:09 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. 
	Creates a new list resulting of the successive applications of
	the function ’f’.
	The ’del’ function is used to delete the content of a node if needed.
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.
	del: The address of the function used to delete
	the content of a node if needed.
	Returns the new list and NULL if the allocation fails.
	free the created memory

*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*update;

	if (!lst || !f || !del)
		return (0);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (0);
	update = ptr;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			ft_lstclear(&update, del);
			return (0);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (update);
}
