/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:53 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/25 15:17:41 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_argv(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	if (*argv && argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atol(argv[i]);
		if (!ft_str_isdigit(argv[i]) || ft_is_duplicates(tmp, argv, i++)
			|| tmp < INT_MIN || tmp > INT_MAX)
		{
			ft_putendl_fd("Error", 2);
			exit(0);
		}
	}
	if (argv[1] == NULL)
	{
		ft_free_str(argv);
		exit(0);
	}
	if (argc == 2)
		ft_free_str(argv);
}
