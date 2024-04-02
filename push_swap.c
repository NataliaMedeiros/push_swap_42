/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:35:14 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/29 12:57:47 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*include_numbers(char **numbers)
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

void	push_swap(char **numbers)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	stack_a = include_numbers(numbers);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
}

int	main(int argc, char **argv)
{
	char	**numbers;

	if (argc < 2)
		return (1);
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
	push_swap(numbers);
	if (argc == 2)
		free_array(numbers);
	return (0);
}
