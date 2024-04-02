/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 14:00:35 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:49:37 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_operation(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		bonus_swap(stack_a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		bonus_swap(stack_b);
	else if (ft_strcmp(operation, "pa\n") == 0)
		bonus_push(stack_b, stack_a);
	else if (ft_strcmp(operation, "pb\n") == 0)
		bonus_push(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		bonus_rotate(stack_a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		bonus_rotate(stack_b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		bonus_reverse_rotate(stack_a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		bonus_reverse_rotate(stack_b);
	else if (ft_strcmp(operation, "rr\n") == 0
		|| ft_strcmp(operation, "rrr\n") == 0)
		double_rotation(stack_a, stack_b, operation);
	else
		return (0);
	return (1);
}

void	read_input(t_list **stack_a, t_list **stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!check_operation(operation, stack_a, stack_b))
			write(1, "Error\n", 6);
		free (operation);
		operation = get_next_line(0);
	}
}

t_list	*include(char **numbers)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = ft_lstnew(numbers[0]);
	if (stack_a == NULL)
		return (NULL);
	i++;
	while (numbers[i] != NULL)
	{
		ft_lstadd_back(&stack_a, numbers[i]);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	char	**numbers;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	if (!is_valid(numbers))
	{
		if (argc == 2)
			free_array(numbers);
		error_exit();
	}
	stack_a = include(numbers);
	read_input(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
