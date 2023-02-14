/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:59:38 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/14 13:16:13 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(void)
{
	printf ("\e[0;31m 🔗invalid argument\n\e[0m");
}

/*
  i[0] => stores the ascii of the first quote found
  i[1] => stores the position of the first quote
  i[2] => stores the ascii of the quotes
  i[3] => stores the position of the quotes
  i[4] => stores the number of quotes found
*/
int	uneven_quotes(char *str)
{
	int	j;
	int	i[5];

	j = -1;
	ft_bzero(i, 5 * sizeof(int));
	while (str[++j])
	{
		if (str[j] == '\"' || str[j] == '\'')
		{
			if (!(i[0] || i[4] % 2))
			{
				i[0] = str[j];
				i[1] = j;
			}
			i[2] = str[j];
			i[3] = j;
			if (i[2] == i[0])
				i[4]++;
		}
	}
	if (i[4] % 2)
	{
		printf (SYNTAX_ERR_C, i[2]);
		return (1);
	}
	return (0);
}

/*
	quotes => true if it finds a quote and false when the quote ends
	i[1] => stores the ascii of the first quote found
	i[2] => stores the ascii of the current quote found
	i[3] => stores the ascii of the last occurence of the quotes
	i[4] => track the last occurrence of the | symbol in the string
	i[5] => tracks the number of alphanumeric characters
	i[6] => tracks the number of pipe symbols
*/

int wrong_piping(char *str)
{
	int	i[7];
	int	j;
	int	quotes;

	j = -1;
	ft_bzero(i, 7 * sizeof(int));
	quotes = 0;
	while (str[++j])
	{
		while (str[j] == ' ')
			j++;
	
		if (str[j] == '\"' || str[j] == '\'')
		{
			if (!quotes)
			{
				quotes = str[j];
				i[1] = j;
			}
			i[2] = str[j];
			i[3] = j;
			if (i[2] == quotes)
				quotes = 0;
		}
		if (ft_isalnum(str[j]))
		    i[5]++;
		if (str[j] == '|' && !quotes)
		{
			if (j == 0 || str[j + 1] == '\0')
			{
				printf(SYNTAX_ERR_C, '|');
				return (1);
			}
			if (!(i[5]))
				return (1);
			i[4] = j;
			i[6]++;
			j++;
			while (str[j] == ' ')
				j++;
			if (str[j] == '\0')
			{
				printf(SYNTAX_ERR_C, '|');
				return (1);
			}
			if (ft_isalnum(str[j]))
				return (0);
		}
	}
	if (i[6] == 0)
	    return (0);
	printf(SYNTAX_ERR_C, '|');
	return (1);
}



/*
	quotes => true if it finds a quote and false when the quote ends
	i[1] => stores the ascii of the first quote found
	i[2] => stores the ascii of the current quote found
	i[3] => stores the ascii of the last occurence of the quotes
	i[4] => track the last occurrence of the | symbol in the string
	i[5] => tracks the number of alphanumeric characters
	i[6] => tracks the number of rd symbols
*/


int wrong_redirection(char *str, char rd)
{
	int	i[7];
	int	j;
	int	quotes;

	j = -1;
	ft_bzero(i, 7 * sizeof(int));
	quotes = 0;
	while (str[++j])
	{
		while (str[j] == ' ')
			j++;
	
		if (str[j] == '\"' || str[j] == '\'')
		{
			if (!quotes)
			{
				quotes = str[j];
				i[1] = j;
			}
			i[2] = str[j];
			i[3] = j;
			if (i[2] == quotes)
				quotes = 0;
		}
		if (ft_isalnum(str[j]))
		    i[5]++;
		if (str[j] == rd && !quotes)
		{
			if (str[j + 1] == rd && str[j + 2] == rd)
			{
				printf(SYNTAX_ERR_C, rd);
				return (1);
			}
			if (str[j + 1] == rd)
				j++;
			if (j == 0 || str[j + 1] == '\0' || !(i[5]))
			{
				printf(SYNTAX_ERR_C, rd);
				return (1);
			}
			i[4] = j;
			i[6]++;
			if (i[6] > 2)
			{
				printf(SYNTAX_ERR_C, rd);
				return (1);
			}
			j++;
			while (str[j] == ' ')
				j++;
			if (str[j] == '\0')
			{
				printf(SYNTAX_ERR_C, rd);
				return (1);
			}
			if (ft_isalnum(str[j]))
				return (0);
		}
	}
	if (i[6] == 0)
	    return (0);
	printf(SYNTAX_ERR_C, rd);
	return (1);
}




int no_errors(char *str)
{
	if (uneven_quotes(str))
		return (1);
	if (wrong_piping(str))
		return (1);
	if (wrong_redirection(str, '>') || wrong_redirection(str, '<'))
		return (1);
	//if a forbidden character
	return (0);
}