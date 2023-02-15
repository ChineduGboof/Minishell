/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:13:06 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/15 14:19:19 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*lexer(char *str, t_list *data)
{
	char	**words;
	char	*exp_str;
	int		i;


	// add white space to all special characters
	str = add_space(str);
	printf("add_space: %s\n", str);
	// remove excess white space
	remove_spaces(str);
	printf("removed space: %s\n", str);
	// expand any string with a dollar sign in it but ignore any with a ''
	exp_str = expand_env(str, data);
	// split using space if not inside quotes
	int wc = split_string(exp_str, &words);
	

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
