/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:35:19 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 14:55:46 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "my_library/my_library.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_list
{
	int				numb;
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

#endif