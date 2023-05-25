/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:20:10 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/25 13:25:43 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"  //supprime
# include "limits.h"
# include "./libft/libft.h"

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_node;

void	ft_sort(t_node **stack_a, t_node **stack_b);
int		ft_stack_size(t_node *first_node);
void	ft_simple_sort(t_node **stack_a, t_node **stack_b);
void	ft_radix_sort(t_node **stack_a, t_node **stack_b);
void	ft_sort_three(t_node **stack_a);
void	ft_sort_four(t_node **stack_a, t_node **stack_b);
void	ft_sort_five(t_node **stack_a, t_node **stack_b);
int		ft_min_index(t_node **stack, int content);
int		ft_get_distance_to_node(t_node **stack, int index);
void	ft_check_argv(int argc, char **argv);
int		ft_is_duplicates(int num, char **argv, int i);
void	ft_create_stack(t_node **stack, int agrc, char **argv);
t_node	*ft_create_node(int content);
void	ft_add_node_to_back(t_node **stack, t_node *new_node);
t_node	*ft_get_last_node(t_node *first_node);
void	ft_free_stack(t_node **stack);
void	ft_free_str(char **str);
int		ft_str_isdigit(char *str);
long	ft_atol(const char *str);
int		ft_is_sort(t_node **stack);
void	ft_add_index_to_stack(t_node **stack);
t_node	*ft_get_next_min(t_node **stack);
void	push(t_node **stack_src, t_node **stack_dst);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

#endif