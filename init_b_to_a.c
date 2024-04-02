/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_b_to_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 12:20:38 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:21:54 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->numb > stack_b->numb
				&& current_a->numb < best_match_index)
			{
				best_match_index = current_a->numb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
