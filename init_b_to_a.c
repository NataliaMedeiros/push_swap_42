#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	long			min;
	t_list			*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->numb < min)
		{
			min = stack->numb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

static void	set_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->numb > b->numb
				&& current_a->numb < best_match_index)
			{
				best_match_index = current_a->numb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
