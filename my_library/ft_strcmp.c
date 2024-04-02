/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 18:03:28 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:28:47 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}
