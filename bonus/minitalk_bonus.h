/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:09:04 by atakeddi          #+#    #+#             */
/*   Updated: 2022/03/15 19:05:42 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

typedef struct sigaction	t_sa;

void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_putstr(char *c);
void	ft_putchar(char c);
int		ft_strlen(char *s);
void	sigusr_handler(int signum, siginfo_t *info, void *cont);
void	handler_Bonus(int i);

#endif