/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 12:14:07 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:22:56 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head, char *operation)
{
	t_list	*last;
	t_list	*aux;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	aux = *head;
	(*head) = (*head)->next;
	aux->next = NULL;
	if (operation[0] != '\0')
		ft_putendl(operation);
}

void	reverse_rotate(t_list **head, char *operation)
{
	t_list	*last;
	t_list	*aux;

	last = *head;
	while (last->next != NULL)
	{
		aux = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	aux->next = NULL;
	if (operation[0] != '\0')
		ft_putendl(operation);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
	{
		rotate(stack_a, "");
		rotate(stack_b, "");
		ft_putendl("rr");
	}
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		reverse_rotate(a, "");
		reverse_rotate(b, "");
		ft_putendl("rrr");
	}
	current_index(*a);
	current_index(*b);
}
