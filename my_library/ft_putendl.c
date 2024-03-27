/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 15:16:15 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 11:43:55 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}