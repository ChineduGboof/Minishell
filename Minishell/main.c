/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:08 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/10 00:50:37 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	handle when a user presses Control D
*/
#include "minishell.h"

int main (int argc, char *argv[], char *envp[])
{
	// t_list	*data;
	char	*args;
	// char	**tokens;

	if (argc == 1)
	{
		// data = calloc(1, sizeof(t_list));
		while (1)
		{
			args = readline("Minishell $: ");
			if (!args)			//takes care of Cntrl D seg fault
				break;
			if (ft_strlen(args))	//if args is not empty, then do
			{
				add_history(args);	//adds the args to the history
				if (no_errors(args) == 0)
				{
					lexer(args);
				}
				else
				{
					free(args);
					continue ;
				}
			}
				
		}
		// free(data);
	}
	else
	{
		printf("\e[0;31m %s: No such file or directory ⚙️\n\e[0m", argv[1]);
		return (1);
	}
	(void)envp;
}
