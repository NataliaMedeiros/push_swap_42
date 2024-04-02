/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_a_to_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 12:20:18 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:20:19 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_index;

	while (stack_a)
	{
		best_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->numb < stack_a->numb
				&& current_b->numb > best_index)
			{
				best_index = current_b->numb;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->is_above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node != NULL)
		{
			if (stack_a->target_node->is_above_median)
				stack_a->push_cost += stack_a->target_node->index;
			else
				stack_a->push_cost += len_b - (stack_a->target_node->index);
		}
		stack_a = stack_a->next;
	}
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
