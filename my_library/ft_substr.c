/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 09:22:34 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 11:45:15 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "my_library.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		substring[i] = s[start];
		start++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}