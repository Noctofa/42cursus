/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:08:54 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/24 19:29:42 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*prev_last_node;
	t_node	*last_node;

	if (ft_stack_size(*stack) > 2)
	{
		prev_last_node = *stack;
		while (prev_last_node->next->next)
			prev_last_node = prev_last_node->next;
		last_node = prev_last_node->next;
		prev_last_node->next = NULL;
		last_node->next = *stack;
		*stack = last_node;
	}
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
