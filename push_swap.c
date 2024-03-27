/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:35:14 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 15:08:07 by nmedeiro      ########   odam.nl         */
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
	int		i;

	i = 0;
	stack_a = include_numbers(numbers);
	/*Ja implementeo PREV na minha linked list*/
	stack_a = sort(stack_a);
	//free_stack(&stack_a);
}

int	main(int argc, char **argv)
{
	char	**numbers;

	/*This if handle when there're no argv to the program*/
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
	//fazer melhorias na implementacao do iniciar stack
	push_swap(numbers);
	if (argc == 2)
		free_array(numbers);
	return (0);
} 