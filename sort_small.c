/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/28 10:34:12 by natalia       #+#    #+#                 */
/*   Updated: 2024/03/29 12:48:41 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_list **stack_a)
{
	int	max;

	max = get_max(*stack_a);
	if ((*stack_a)->numb == max)
		rotate(stack_a, "ra");
	else if ((*stack_a)->next->numb == max)
		reverse_rotate(stack_a, "rra");
	if ((*stack_a)->numb > (*stack_a)->next->numb)
		swap(stack_a, "sa");
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	while ((*stack_a)->numb != min)
	{
		if ((*stack_a)->next->numb == min)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
	push(stack_a, stack_b, "pb");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa");
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	while ((*stack_a)->numb != min)
	{
		if ((*stack_a)->next->numb == min)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
	push(stack_a, stack_b, "pb");
	min = get_min(*stack_a);
	while ((*stack_a)->numb != min)
	{
		if ((*stack_a)->next->numb == min)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
	push(stack_a, stack_b, "pb");
	if ((*stack_b)->numb < (*stack_b)->next->numb)
		swap(stack_a, "sa");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa");
	push(stack_b, stack_a, "pa");
}
