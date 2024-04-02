/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 18:01:32 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 12:28:50 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
