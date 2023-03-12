/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:22:21 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 16:10:31 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_quoted_string(const char *s, int i)
{
	char	c;

	if ((s[i] == 39 || s[i] == 34))
	{
		c = s[i];
		i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

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

int	scan_rd(t_data *data)
{
	int	rd_num;
	int	x;
	int	i;
	int	rd_fname_len;

	rd_num = count_rd(data);
	x = 0;
	i = 0;
	if (!valid_rd(x, data, rd_num))
		return (0);
	alloc_rd(data, rd_num);
	while (x < rd_num)
	{
		i = find_rd(data, i);
		rd_fname_len = 0;
		rd_fname_len = get_rd_fname_size(data, i);
		if (rd_fname_len == 0)
			return (0);
		data->rd[x] = ft_calloc(sizeof(char), rd_fname_len + 1);
		escape_rd(data, &i);
		x++;
	}
	return (1);
}

int	check_input_errors(int pipe_num, char *cmd_line, t_quote *for_all)
{
	if (for_all->dquote == 1)
	{
		print_error("error: unclosed quotes");
		return (0);
	}
	if (count_pipes(cmd_line, pipe_num) == 100)
		return (0);
	return (1);
}
