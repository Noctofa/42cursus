/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:57 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/24 21:30:52 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

int	ft_stack_size(t_node *first_node)
{
	int	stack_size;

	stack_size = 0;
	while (first_node)
	{
		stack_size++;
		first_node = first_node->next;
	}
	return (stack_size);
}

void	ft_simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (!ft_is_sort(stack_a) || ((!ft_stack_size(*stack_a)) == 0)
		|| ft_stack_size(*stack_a) != 1)
	{
		size = ft_stack_size(*stack_a);
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			ft_sort_three(stack_a);
		else if (size == 4)
			ft_sort_four(stack_a, stack_b);
		else if (size == 5)
			ft_sort_five(stack_a, stack_b);
	}
}

void	ft_radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_stack_size(*stack_a);
	while (!ft_is_sort(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_stack_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}
