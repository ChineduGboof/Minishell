/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_rd_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:01 by gboof             #+#    #+#             */
/*   Updated: 2023/03/17 14:27:51 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_open(char *str)
{
	int	fd;

	fd = open(str, O_RDWR, 0777);
	if (fd < 0)
	{
		write(2, "invalid fd\n", 11);
		exit(1);
	}
	return (fd);
}

int	ft_open_ap(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		write(2, "invalid fd\n", 11);
		exit(1);
	}
	return (fd);
}

int	ft_open_rp(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "invalid fd\n", 11);
		exit(1);
	}
	return (fd);
}
