/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:11:57 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/28 10:17:30 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, char *operation)
{
	t_list	*new_head;

	new_head = *head;
	new_head = new_head->next;
	(*head)->next = new_head->next;
	new_head->next = (*head);
	*head = new_head;
	ft_putendl(operation);
}

void	push(t_list **head_src, t_list **head_dest, char *operation)
{
	t_list	*temp;

	temp = *head_src;
	*head_src = (*head_src)->next;
	if ((*head_dest) == NULL)
		temp->next = NULL;
	else
		temp->next = *head_dest;
	*head_dest = temp;
	ft_putendl(operation);
}

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
	ft_putendl(operation);
}
