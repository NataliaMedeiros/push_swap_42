/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:09:21 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/28 15:27:30 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list **head)
{
	t_list	*temp;

	temp = (*head);
	while (temp->next != NULL && (temp->numb < temp->next->numb))
		temp = temp->next;
	if (temp->next == NULL)
		return (1);
	return (0);
}

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

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	printf("stack: %d, top_node: %d e name: %c\n", (*stack)->numb, top_node->numb, stack_name);
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->is_above_median)
				rotate(stack, "ra");
			else
				reverse_rotate(stack, "rra");
		}
		else if (stack_name == 'b')
		{
			if (top_node->is_above_median)
				rotate(stack, "rb");
			else
				reverse_rotate(stack, "rrb");
		}
	}
}

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
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

void	*sort(t_list **stack_a, t_list **stack_b)
{
	int		list_size;

	if ((*stack_a)->next == NULL)
		return (stack_a);
	list_size = ft_lstsize(*stack_a);
	if (sorted(stack_a))
		return (stack_a);
	else if (list_size == 2)
		swap(stack_a, "sa");
	else if (list_size == 3)
		sort_three(stack_a);
	else if (list_size == 4)
		sort_four(stack_a, stack_a);
	else if (list_size == 5)
		sort_five(stack_a, stack_a);
	else
	{
		if (list_size-- > 3 && !sorted(stack_a))
			push(stack_a, stack_b, "pb");
		if (list_size-- > 3 && !sorted(stack_a))
			push(stack_a, stack_b, "pb");
		while (list_size-- > 3 && !(sorted(stack_a)))
		{
			init_nodes_a(*stack_a, *stack_b);
			move_a_to_b(stack_a, stack_b);
			print_stack("A----->", *stack_a);
			print_stack("B----->", *stack_b);
		}
		sort_three(stack_a);
		while (*stack_b)
		{
			init_nodes_b(*stack_a, *stack_b);
			move_b_to_a(stack_a, stack_b);
		}
	}
	return (stack_a);
}
