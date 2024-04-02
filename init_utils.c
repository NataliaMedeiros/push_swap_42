/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 11:58:45 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/02 13:17:30 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		++i;
	}
}

t_list	*find_max(t_list *stack)
{
	long	max;
	t_list	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->numb > max)
		{
			max = stack->numb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*find_min(t_list *stack)
{
	long			min;
	t_list			*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->numb < min)
		{
			min = stack->numb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
