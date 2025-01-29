/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:25:10 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/20 13:26:29 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  ", 1);
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("  ", 0);
	rl_redisplay();
}

void signal_handler()
{
    signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
