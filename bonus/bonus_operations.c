/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:11:57 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:48:25 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	bonus_swap(t_list **head)
{
	t_list	*new_head;

	new_head = *head;
	new_head = new_head->next;
	(*head)->next = new_head->next;
	new_head->next = (*head);
	*head = new_head;
}

void	bonus_push(t_list **head_src, t_list **head_dest)
{
	t_list	*temp;

	temp = *head_src;
	*head_src = (*head_src)->next;
	if ((*head_dest) == NULL)
		temp->next = NULL;
	else
		temp->next = *head_dest;
	*head_dest = temp;
}

void	bonus_rotate(t_list **head)
{
	t_list	*last;
	t_list	*aux;

	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *head;
	aux = *head;
	(*head) = (*head)->next;
	aux->next = NULL;
}

void	bonus_reverse_rotate(t_list **head)
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
}

void	double_rotation(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (ft_strcmp(operation, "rr\n") == 0)
	{
		bonus_rotate(stack_a);
		bonus_rotate(stack_b);
	}
	else if (ft_strcmp(operation, "rrr\n") == 0)
	{
		bonus_reverse_rotate(stack_a);
		bonus_reverse_rotate(stack_b);
	}
}
