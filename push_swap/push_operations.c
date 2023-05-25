/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:25:08 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/24 20:31:15 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_src) != 0)
	{
		tmp = *stack_src;
		*stack_src = (*stack_src)->next;
		tmp->next = *stack_dst;
		*stack_dst = tmp;
	}
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
