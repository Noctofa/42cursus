/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:35:45 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/25 13:00:00 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_index(t_node **stack, int content)
{
	t_node	*first_node;
	int		min_index;

	first_node = *stack;
	min_index = first_node->index;
	while (first_node->next)
	{
		first_node = first_node->next;
		if ((first_node->index < min_index) && first_node->index != content)
			min_index = first_node->index;
	}
	return (min_index);
}

int	ft_get_distance_to_node(t_node **stack, int index)
{
	t_node	*first_node;
	int		distance_node;

	distance_node = 0;
	first_node = *stack;
	while (first_node)
	{
		if (first_node->index == index)
			break ;
		distance_node++;
		first_node = first_node->next;
	}
	return (distance_node);
}

void	ft_sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == ft_min_index(stack_a, -1)
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index
		== ft_min_index(stack_a, ft_min_index(stack_a, -1)))
	{
		if ((*stack_a)->next->index < (*stack_a)->index)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == ft_min_index(stack_a, -1))
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	ft_sort_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_to_node(stack_a, ft_min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (!ft_is_sort(stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		pa(stack_b, stack_a);
	}
}

void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_to_node(stack_a, ft_min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (!ft_is_sort(stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
}
