/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:13:06 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/14 13:23:48 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*lexer(char *str)
{
	char	**words;
	int		i;


	// add white space to all special characters
	str = add_space(str);
	printf("add_space: %s\n", str);
	// remove excess white space
	remove_spaces(str);
	printf("removed space: %s\n", str);
	// split using space if not inside quotes
	int wc = split_string(str, &words);
	// free the malloc double pointer array in split_strings
	i = 0;
	while (i < wc)
	{
		printf("str[%d] = %s\n", i, words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	free(str);

	return (str);
}
