/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 14:48:47 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/29 12:58:10 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
