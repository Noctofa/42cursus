/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:07:48 by sgaspard          #+#    #+#             */
/*   Updated: 2023/04/28 14:00:42 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_isnegatif(char *str, int *sign, int *i)
{
	if (str[*i] == '-')
		*sign = -*sign;
	*i = *i + 1;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	tmp;
	long	res;

	tmp = 0;
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		ft_isnegatif((char *)str, &sign, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[i++] - '0');
		if (res < tmp && sign == 1)
			return (-1);
		if (res != 0 && res < tmp && sign == -1)
			return (0);
	}
	return (sign * res);
}

void	ft_send_bits(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c << i) & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(350);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments\n");
		ft_printf("Format: [./client <SERVER ID(PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
		ft_send_bits(ft_atoi(argv[1]), argv[2][i++]);
	ft_send_bits(ft_atoi(argv[1]), '\n');
	return (0);
}
