/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:09:21 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 15:09:56 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	sorted(t_list **head)
{
	t_list	*temp;

	temp = (*head);
	while (temp->next != NULL && (temp->stack < temp->next->stack))
		temp = temp->next;
	if (temp->next == NULL)
		return (1);
	return (0);
}

t_list	*sort(t_list *head_a)
{
	t_list	*head_b;
	int		list_size;

	head_b = NULL;
	if (head_a->next == NULL)
		return (head_a);
	list_size = ft_lstsize(head_a);
	if (is_sorted(head_a))
		return (head_a);
	if (list_size == 2)
		sort_two(&head_a);
	else if (list_size == 3)
		sort_three(&head_a);
	else if (list_size == 4)
		sort_four(&head_a, &head_b);
	else if (list_size == 5)
		sort_five(&head_a, &head_b);
	else
	{
		split_list((list_size / 2), &head_a, &head_b);
		sort_a(&head_a, &head_b);
		while (head_b != NULL)
			push(&head_b, &head_a, "pa");
	}
	return (head_a);
}