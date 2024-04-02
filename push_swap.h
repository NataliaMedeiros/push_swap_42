/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:35:19 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:18:49 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "my_library/my_library.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_list
{
	int				numb;
	int				index;
	int				push_cost;
	bool			is_above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*handle errors*/
void	error_exit(void);
int		error_syntax(char **argv);
int		check_doubles(char **argv);
int		is_valid(char **temp);

/*free utils*/
void	free_array(char **args);

/*linked_list*/
t_list	*find_last_node(t_list *head);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **head, void *content);
void	ft_lstdelone(t_list **lst);
int		ft_lstsize(t_list *lst);

/*sort functions*/
void	*sort(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
int		get_max(t_list *head);
int		get_min(t_list *head);
void	sort_bigger(t_list **stack_a, t_list **stack_b, int list_size);
void	prep_for_push(t_list **stack, t_list *top_node, char stack_name);
int	sorted(t_list **head);

/*operations functions*/
void	swap(t_list **head, char *operation);
void	push(t_list **head_src, t_list **head_dest, char *operation);
void	rotate(t_list **head, char *operation);
void	reverse_rotate(t_list **head, char *operation);

void	init_nodes_a(t_list *a, t_list *b);
void	set_cheapest(t_list *stack);
void	current_index(t_list *stack);
void	init_nodes_b(t_list *a, t_list *b);
void	free_stack(t_list **stack);
t_list	*find_max(t_list *stack);
void	move_b_to_a(t_list **a, t_list **b);
void	move_a_to_b(t_list **stack_a, t_list **stack_b);
void	set_cheapest(t_list *stack);
void	current_index(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
t_list	*get_cheapest(t_list *stack);
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);

#endif
