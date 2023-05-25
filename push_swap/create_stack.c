/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:26:12 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/25 15:00:13 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_last_node(t_node *first_node)
{
	if (!first_node)
		return (NULL);
	while (first_node->next)
		first_node = first_node->next;
	return (first_node);
}

void	ft_add_node_to_back(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	if (!new_node)
		return ;
	if (*stack)
	{
		tmp = ft_get_last_node(*stack);
		tmp->next = new_node;
	}
	else
		*stack = new_node;
}

t_node	*ft_create_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_create_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = ft_create_node(ft_atoi(argv[i]));
		ft_add_node_to_back(stack, new);
		i++;
	}
	ft_add_index_to_stack(stack);
	if (argc == 2)
		ft_free_str(argv);
}
