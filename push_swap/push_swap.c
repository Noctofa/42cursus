/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:57 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/09 16:23:08 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_program(argc, argv);
	if (!a || ft_checkdub(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksort(a))
		ft_sort();
	ft_free(&a);
	return (0);
}