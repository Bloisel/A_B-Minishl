/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.signe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:11:00 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/06 17:26:12 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sig_alt(int signum, siginfo_t *info, void *ptr)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		get_exit_status = 130;
	}
	if (signum == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		get_exit_status = 131;
	}
	(void)signum;
	(void)info;
	(void)ptr;
}

void	handle_sig(int signum, siginfo_t *info, void *ptr)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		//rl_replace_line("", 1);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		rl_redisplay();
	}
	(void)signum;
	(void)info;
	(void)ptr;
}

void	init_signal(t_data *dta, struct sigaction *sa, struct termios *terminal)
{
	(void)dta;
	ft_memset(sa, 0, sizeof(struct sigaction));
	sa->sa_sigaction = handle_sig;
	sa->sa_flags = SA_SIGINFO;
	dta->keys = NULL;
	dta->key_done = 0;
	dta->st = 0;
	sigaction(SIGINT, sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDOUT_FILENO, terminal);
	terminal->c_lflag |= ~ISIG;
	terminal->c_cc[VSUSP] = 0;
	terminal->c_lflag ^= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, terminal);
}