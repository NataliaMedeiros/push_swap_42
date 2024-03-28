#include "push_swap.h"

t_list	*find_max(t_list *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_list	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->numb > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->numb; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
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
		if (i <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->numb < a->numb
				&& current_b->numb > best_match_index)
			{
				best_match_index = current_b->numb;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_list *a, t_list *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	printf("Entrei no cost_analysis_a\n");
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		if (a->target_node != NULL)
			printf("target: %d\n", a->target_node->numb);
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->is_above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node != NULL)
		{
			if (a->target_node->is_above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
				a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
			else //If `a` node is indeed above median and its target `b` node is below median
				a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		}
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_list *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	printf("Entrei no set_cheapest\n");
	long			cheapest_value; //To store the value of the cheapest node so far
	t_list	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(stack_a);
	print_index("current_index A", stack_a);
	current_index(stack_b);
	print_index("current_index B", stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
