/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:09:21 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/29 12:54:47 by natalia       ########   odam.nl         */
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

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	// printf("stack: %d, top_node: %d e name: %c\n", (*stack)->numb, top_node->numb, stack_name);
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
		sort_bigger(stack_a, stack_b, list_size);
	return (stack_a);
}
