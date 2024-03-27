/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 18:02:40 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 11:44:07 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

int	look_special_char(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	positive_or_negative;

	i = look_special_char(nptr);
	number = 0;
	positive_or_negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			positive_or_negative = -1;
		}
		i++;
	}
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			number = number * 10 + (nptr[i] - '0');
		else
			return (number * positive_or_negative);
		i++;
	}
	return (number * positive_or_negative);
}