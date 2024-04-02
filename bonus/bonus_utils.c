/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 12:11:57 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 14:58:57 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* 1 means true and 0 means false */
int	is_sorted(t_list *head)
{
	while (head->next != NULL && (head->stack < head->next->stack))
		head = head->next;
	if (head->next == NULL)
		return (1);
	return (0);
}

int	get_min(t_list *head)
{
	int	min;

	min = head->stack;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->stack < min)
			min = head->stack;
	}
	return (min);
}

void	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0)
		free (args[i--]);
	if (args)
		free (args);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
