/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 12:56:25 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:25:09 by natalia       ########   odam.nl         */
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

int	get_max(t_list *head)
{
	int	max;

	max = head->numb;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->numb > max)
			max = head->numb;
	}
	return (max);
}

int	get_min(t_list *head)
{
	int	min;

	min = head->numb;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->numb < min)
			min = head->numb;
	}
	return (min);
}

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
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
