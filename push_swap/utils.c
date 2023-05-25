/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:01:44 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/24 20:45:30 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_get_next_min(t_node **stack)
{
	t_node	*first_node;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	first_node = *stack;
	if (first_node)
	{
		while (first_node)
		{
			if ((first_node->index == -1) && (!has_min || first_node->content
					< min->content))
			{
				min = first_node;
				has_min = 1;
			}
			first_node = first_node->next;
		}
	}
	return (min);
}

void	ft_add_index_to_stack(t_node **stack)
{
	t_node	*first_node;
	int		index;

	index = 0;
	first_node = ft_get_next_min(stack);
	while (first_node)
	{
		first_node->index = index++;
		first_node = ft_get_next_min(stack);
	}
}

int	ft_is_sort(t_node **stack)
{
	t_node	*first_node;

	first_node = *stack;
	while (first_node->next)
	{
		if (first_node->content > first_node->next->content)
			return (0);
		first_node = first_node->next;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr *= neg;
	return (nbr);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
