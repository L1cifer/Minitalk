/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:31:57 by atakeddi          #+#    #+#             */
/*   Updated: 2022/03/11 18:38:46 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int signum, siginfo_t *info, void *cont)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid;

	(void) cont;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		bit = 0;
		c = 0xff;
	}
	if (bit <= 8)
	{
		if (signum == SIGUSR2)
			c |= 0x80 >> bit;
		else if (signum == SIGUSR1)
			c ^= 0x80 >> bit;
		bit++;
	}
	if (bit == 8)
	{
		ft_putchar(c);
		c = 0xFF;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
