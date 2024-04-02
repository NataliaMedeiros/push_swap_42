/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_bigger.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 12:49:35 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:23:15 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->target_node != NULL)
	{
		if (cheapest_node->is_above_median
			&& cheapest_node->target_node->is_above_median)
			rotate_both(stack_a, stack_b, cheapest_node);
		else if (!(cheapest_node->is_above_median)
			&& !(cheapest_node->target_node->is_above_median))
			rev_rotate_both(stack_a, stack_b, cheapest_node);
		prep_for_push(stack_a, cheapest_node, 'a');
		prep_for_push(stack_b, cheapest_node->target_node, 'b');
	}
	push(stack_a, stack_b, "pb");
}

void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push(b, a, "pa");
}

void	init_and_move_a(t_list **stack_a, t_list **stack_b)
{
	init_nodes_a(*stack_a, *stack_b);
	move_a_to_b(stack_a, stack_b);
}

void	sort_bigger(t_list **stack_a, t_list **stack_b, int list_size)
{
	t_list	*max;

	if (list_size-- > 3 && !sorted(stack_a))
		push(stack_a, stack_b, "pb");
	if (list_size-- > 3 && !sorted(stack_a))
		push(stack_a, stack_b, "pb");
	while (list_size-- > 3 && !(sorted(stack_a)))
		init_and_move_a(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	if (!(sorted(stack_a)))
		current_index(*stack_a);
	while (!(sorted(stack_a)))
	{
		max = find_max(*stack_a);
		if (max->is_above_median)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
}
