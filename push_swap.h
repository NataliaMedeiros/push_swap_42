/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:35:19 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 15:33:50 by natalia       ########   odam.nl         */
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

/*free utils*/
void	free_array(char **args);
void	free_stack(t_list **stack);

/*handle errors*/
void	error_exit(void);
int		error_syntax(char **argv);
int		check_doubles(char **argv);
int		is_valid(char **temp);

/*init_a_to_b*/
void	init_nodes_a(t_list *stack_a, t_list *stack_b);

/*init_b_to_a*/
void	init_nodes_b(t_list *stack_a, t_list *stack_b);

/*init_utils*/
void	set_cheapest(t_list *stack);
void	current_index(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);

/*linked_list*/
void	ft_lstadd_back(t_list **head, void *content);
void	ft_lstdelone(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*find_last_node(t_list *head);
t_list	*ft_lstnew(void *content);

/*operations*/
void	swap(t_list **head, char *operation);
void	push(t_list **head_src, t_list **head_dest, char *operation);

/*rotations*/
void	rotate(t_list **head, char *operation);
void	reverse_rotate(t_list **head, char *operation);
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);

/*sort_bigger*/
void	move_a_to_b(t_list **stack_a, t_list **stack_b);
void	move_b_to_a(t_list **a, t_list **b);
void	sort_bigger(t_list **stack_a, t_list **stack_b, int list_size);

/*sort_utils*/
int		sorted(t_list **head);
int		get_max(t_list *head);
int		get_min(t_list *head);
void	prep_for_push(t_list **stack, t_list *top_node, char stack_name);
t_list	*get_cheapest(t_list *stack);

/*sort*/
void	*sort(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);

#endif
