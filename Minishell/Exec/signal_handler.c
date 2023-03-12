/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:20:16 by gboof             #+#    #+#             */
/*   Updated: 2023/03/12 18:00:01 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	signal_controller(int sig_num)
{
	if (sig_num == SIGINT)
	{
		if (waitpid(-1, &s_data->return_state, WNOHANG) == -1)
		{
			rl_on_new_line();
			rl_redisplay();
			write(STDERR_FILENO, "  \n", 4);
			// rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			s_data->return_state = 1;
		}
	}
	else if (sig_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", 2);
		s_data->return_state = 131;
	}
	else if (sig_num == SIGSEGV)
	{
		printf("\033[1;31m*** _____SEGMENTATION_____FAULT_____ ***\n");
		exit(EXIT_FAILURE);
	}
}

void	trap_signals(void)
{
	signal(SIGINT, signal_controller);
	signal(SIGQUIT, signal_controller);
	signal(SIGSEGV, signal_controller);
}
