/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 15:09:21 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:25:27 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	*sort(t_list **stack_a, t_list **stack_b)
{
	int		list_size;

	if ((*stack_a)->next == NULL)
		return (stack_a);
	list_size = ft_lstsize(*stack_a);
	if (sorted(stack_a))
		return (stack_a);
	else if (list_size == 2)
		swap(stack_a, "sa");
	else if (list_size == 3)
		sort_three(stack_a);
	else
		sort_bigger(stack_a, stack_b, list_size);
	return (stack_a);
}
