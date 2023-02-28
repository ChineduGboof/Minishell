/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:03:22 by cegbulef          #+#    #+#             */
/*   Updated: 2023/02/28 19:10:37 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	copy_op_and_file =>copy_rd_n_fname
	copies the rd into the operator array(op)
	then copies the file name into the fname array
*/
void	copy_rd_n_fname(t_data *data, int x)
{
	int	i;
	int	rd_type;
	int	rd_fsize;

	i = 0;
	rd_type = 0;
	rd_fsize = 0;
	while (data->rd[x][i] == '>' || data->rd[x][i] == '<')
	{
		data->op[x][rd_type] = data->rd[x][i];
		i++;
		rd_type++;
	}
	data->op[x][rd_type] = 0;
	i++;
	while (data->rd[x][i])
	{
		data->fname[x][rd_fsize] = data->rd[x][i];
		i++;
		rd_fsize++;
	}
	data->fname[x][rd_fsize] = 0;
}

/*
	allocate_op_and_file => alloc_rd_n_fname
	first looping thru the argument, it gets what type of rd
	whether its a single or double redirection
	next it allocates memory in the op array for the rd
	next it increments past the space and counts the rd filename size
	">> file1.txt"
	next it allocates memory for the fname
*/
void	alloc_rd_n_fname(t_data *data, int x)
{
	int	i;
	int	rd_type;
	int	rd_fsize;

	i = 0;
	rd_type = 0;
	rd_fsize = 0;
	while (data->rd[x][i] == '>' || data->rd[x][i] == '<')
	{
		i++;
		rd_type++;
	}
	data->op[x] = malloc(rd_type + 1);
	i++;
	while (data->rd[x][i])
	{
		i++;
		rd_fsize++;
	}
	data->fname[x] = malloc(rd_fsize + 1);
}

/*
	copy_details => sort_rd_n_fname
	first it gets the num of rd's present
	looping using that it calls the two functions
	the first one allocates memory for the rd type and the file size
	the next functions copies the rd and filename into their different arrays	
*/
int	sort_rd_n_fname(t_data *data)
{
	int	rd_num;
	int	x;

	x = 0;
	rd_num = count_rd(data);
	while (x < rd_num)
	{
		alloc_rd_n_fname(data, x);
		copy_rd_n_fname(data, x);
		x++;
	}
	return (0);
}

/*
	full_copy => copy_rd_arg2
	copies the rd file name
*/
void	copy_rd_arg2(t_data *data, int i, int j, int x)
{
	char	c;

	while (!ft_isspace(data->cmd_args[i]) && (data->cmd_args[i] != '<'
			&& data->cmd_args[i] != '>') && data->cmd_args[i])
	{
		if (data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"')
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c)
			{
				data->rd[x][j] = data->cmd_args[i];
				j++;
				i++;
			}
			i++;
		}
		else
		{
			data->rd[x][j] = data->cmd_args[i];
			j++;
			i++;
		}
	}
	data->rd[x][j] = 0;
}

/*
	copy_op_line
	"cat < input.txt > output.txt";
	copies the rd to the rd array
	adds a space
	next it calls full_copy
*/
int	copy_rd_arg(t_data *data, int i, int x)
{
	int		j;

	j = 0;
	while ((data->cmd_args[i] == '<' || data->cmd_args[i] == '>')
		&& data->cmd_args[i])
	{
		data->rd[x][j] = data->cmd_args[i];
		i++;
		j++;
	}
	while (ft_isspace(data->cmd_args[i]) && data->cmd_args[i])
		i++;
	data->rd[x][j] = ' ';
	j++;
	copy_rd_arg2(data, i, j, x);
	return (0);
}

/*
	copy_all_op => copy_all_rd_args
	first counts the number of redirections
	next it locates the position of the rd
	copies the rd and the filename
*/
int	copy_all_rd_args(t_data *data)
{
	int	rd_num;
	int	x;
	int	i;
	int	rd_size;

	i = 0;
	rd_num = count_rd(data);
	x = 0;
	while (x < rd_num)
	{
		i = find_rd_pos(data, i);
		copy_rd_arg(data, i, x);
		rd_size = get_rd_fname_size(data, i);
		if (rd_size == 0)
			return (0);
		escape_rd(data, &i);
		x++;
	}
	return (0);
}

/*
	name => count_op
	Looping thru the argument
	check for a quotation while looping and skip past it
	if you see the < or > op, count how many redirections are in the string
	the flags are to make sure you count both the 2 and 1 rd as 1 each
*/

int count_rd(t_data *data)
{
	int		count;
	int		x;
	bool	i;

	count = 0;
	x = 0;
	i = true;
	while (data->cmd_args[x])
	{
		x = pos_of_closing_quotes(x, data);
		if ((data->cmd_args[x] == '<' || data->cmd_args[x] == '>') && i)
		{
			i = false;
			count++;
		}
		else if ((data->cmd_args[x] != '<' && data->cmd_args[x] != '>')
			&& i == 0)
			i = true;
		x++;
	}
	return (count);
}

/*
	check_rd => scan_rd
	counts first the number of redirections in the string
	checks if all redirections have valid filenames
	allocates memory for the redirections
	For example, suppose the command line argument array is {"echo", "hello", ">", "file.txt"}.
	find_next_rd would be used to identify the index of the ">" symbol, which is 2 in this case. 
	escape_rd would then be used to adjust the index to the start of the next input redirection filename,
	which is "file.txt" in this case.
*/

int	scan_rd(t_data *data)
{
	int	rd_num;
	int	x;
	int	i;
	int	rd_fname_size;

	rd_num = count_rd(data);
	x = 0;
	i = 0;
	if (!valid_rd(x, data, rd_num))
		return (0);
	alloc_rd(data, rd_num);
	while (x < rd_num)
	{
		i = find_rd(data, i);
		rd_fname_size = 0;
		rd_fname_size = get_rd_fname_size(data, i);
		if (rd_fname_size == 0)
			return (0);
		data->rd[x] = ft_calloc(sizeof(char), rd_fname_size + 1);
		escape_rd(data, &i);
		x++;
	}
	return (1);
}

/*
	hair_extension => valid_rd
	hair_extension checks for valid redirections by iterating over each redirection 
	and checking if it has a valid filename associated with it.

*/
int	valid_rd(int x, t_data *data, int rd_num)
{
	int	rd_fname_len;
	int	i;

	i = 0;
	while (x < rd_num)
	{
		i = find_rd(data, i);
		rd_fname_len = get_rd_fname_size(data, i);
		if (rd_fname_len == 0)
			return (0);
		escape_rd(data, &i);
		x++;
	}
	return (1);
}

/*
	check_rd_size => get_rd_fname_size
	starts looping from the first redirection position, passed in by rd
	If it sees two opposite redirections together(<>), it throws an error message
	once we we see a complete rd, we increment j to 2
	next it loops through any whitespaces
	then it checks if there is a file name after the rd or another rd
	it throws an error if it finds another rd instead of a file name
	it returns the size of the filename of the rd
*/

int	get_rd_fname_size(t_data *data, int rd)
{
	int		j;

	j = 0;
	while ((data->cmd_args[rd] == '<' || data->cmd_args[rd] == '>')
		&& data->cmd_args[rd] && j < 2)
	{
		if ((data->cmd_args[rd] == '>' && data->cmd_args[rd + 1] == '<'))
		{
			printf(SYNTAX_ERR_C, data->cmd_args[rd + 1]);
			rl_on_new_line();
			return (0);
		}
		rd++;
		j++;
	}
	j++;
	while (ft_isspace(data->cmd_args[rd]) && data->cmd_args[rd])
		rd++;
	if (no_rd_fname(data, rd))
		return (0);
	j = rd_fname_size(data, rd, j);
	return (j);
}


/*
	size_op_from_full => rd_fname_size
	It loops thru the string starting from the first valid filename
	it confirms to make sure its not a rd and if it isnt,
	it checks if there is a quotation mark and skips anything inside
	it returns the length of the amount of characters in the filename
	which is after the redirection
*/

int	rd_fname_size(t_data *data, int i, int j)
{
	char	c;

	while ((!ft_isspace(data->cmd_args[i])) && data->cmd_args[i]
		&& (data->cmd_args[i] != '<' && data->cmd_args[i] != '>'))
	{
		if (no_rd_fname2(data, i))
			return (0);
		else if (data->cmd_args[i] == '\'' || data->cmd_args[i] == '\"')
		{
			c = data->cmd_args[i];
			i++;
			while (data->cmd_args[i] != c && data->cmd_args[i])
			{
				j++;
				i++;
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}

// char	*check_expand(char *cmd, t_data *data)
// {
// 	int		i[3];
// 	char	*final_expanded;

// 	i[0] = 0;
// 	if (!checker(cmd))
// 		return (NULL);
// 	final_expanded = cmd;
// 	final_expanded = check_expand_helper_final(final_expanded, i, data);
// 	return (final_expanded);
// }