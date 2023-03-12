/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:07:33 by cegbulef          #+#    #+#             */
/*   Updated: 2022/11/20 17:34:20 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.
	lst: The address of a pointer to a node.
	del: The address of the function used to delete
	the content of the node.
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = ptr;
	}
	*lst = NULL;
}
