/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_linked_list_utils.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 21:37:34 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 12:38:23 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*find_last_node(t_list *head)
{
	t_list	*last_node;

	last_node = head;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	new_element->stack = ft_atoi(content);
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back(t_list **head, void *content)
{
	t_list	*current_node;
	t_list	*new_node;

	current_node = *head;
	while (current_node->next != NULL)
		current_node = current_node->next;
	new_node = ft_lstnew(content);
	current_node->next = new_node;
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = (*lst)->next;
		free(*lst);
	}
	free (temp);
	return ;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
