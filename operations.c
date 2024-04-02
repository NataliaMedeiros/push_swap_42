/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:11:57 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:22:12 by natalia       ########   odam.nl         */
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
	if (operation[0] != '\0')
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
	if (operation[0] != '\0')
		ft_putendl(operation);
}
