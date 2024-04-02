/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 18:09:56 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:54:35 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../my_library/my_library.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_list
{
	int				stack;
	struct s_list	*next;
}					t_list;

void	read_input(t_list **stack_a, t_list **stack_b);

void	error_exit(void);

int		is_number(char **argv);

int		check_doubles(char **argv);

int		check_limits(char **argv);

int		is_valid(char **temp);

t_list	*find_last_node(t_list *head);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_back(t_list **head, void *content);

void	ft_lstdelone(t_list **lst);

int		ft_lstsize(t_list *lst);

void	free_array(char **args);

void	free_stack(t_list **stack);

int		is_sorted(t_list *head);

void	double_rotation(t_list **stack_a, t_list **stack_b, char *operation);
void	bonus_swap(t_list **head);
void	bonus_push(t_list **head_src, t_list **head_dest);
void	bonus_rotate(t_list **head);
void	bonus_reverse_rotate(t_list **head);

#endif
