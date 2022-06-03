/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:32:30 by atakeddi          #+#    #+#             */
/*   Updated: 2022/03/11 18:23:52 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signals(char *message, int pid, size_t len)
{
	size_t		i;
	int			shift;

	i = 0;
	while (i <= len)
	{
		shift = -1;
		while (++shift < 8)
		{
			if (message[i] & 0x80 >> shift)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("client : invalid arguments \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	send_signals(av[2], pid, ft_strlen(av[2]));
	return (0);
}
