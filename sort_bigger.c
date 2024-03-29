/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_bigger.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 12:49:35 by natalia       #+#    #+#                 */
/*   Updated: 2024/03/29 12:54:53 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheapest(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//arrumar funcao
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
	{
		rotate(stack_a, "ra");
		rotate(stack_b, "rb");
	}
	current_index(*stack_a);
	current_index(*stack_b);
}

//arrumar funcao
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(b, "rrb");
	}
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->target_node != NULL)
	{
		if (cheapest_node->is_above_median
			&& cheapest_node->target_node->is_above_median)
			rotate_both(stack_a, stack_b, cheapest_node);//arrumar funcao
		else if (!(cheapest_node->is_above_median)
			&& !(cheapest_node->target_node->is_above_median))
			rev_rotate_both(stack_a, stack_b, cheapest_node);//arrumar funcao
		prep_for_push(stack_a, cheapest_node, 'a');
		prep_for_push(stack_b, cheapest_node->target_node, 'b');
	}
	push(stack_a, stack_b, "pb");
}

static void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push(b, a, "pa");
}

void	sort_bigger(t_list **stack_a, t_list **stack_b, int list_size)
{
		if (list_size-- > 3 && !sorted(stack_a))
			push(stack_a, stack_b, "pb");
		if (list_size-- > 3 && !sorted(stack_a))
			push(stack_a, stack_b, "pb");
		while (list_size-- > 3 && !(sorted(stack_a)))
		{
			init_nodes_a(*stack_a, *stack_b);
			move_a_to_b(stack_a, stack_b);
		}
		sort_three(stack_a);
		while (*stack_b)
		{
			init_nodes_b(*stack_a, *stack_b);
			move_b_to_a(stack_a, stack_b);
		}
		while (!(sorted(stack_a)))
		{
			if ((*stack_a)->numb > find_last_node(*stack_a)->numb)
				rotate(stack_a, "ra");
		}
}
